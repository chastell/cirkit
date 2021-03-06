/* CirKit: A circuit toolkit
 * Copyright (C) 2009-2015  University of Bremen
 * Copyright (C) 2015-2016  EPFL
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "depth.hpp"

#include <map>
#include <stack>

#include <boost/graph/adjacency_list.hpp>
#include <boost/range/iterator_range.hpp>

namespace cirkit
{

/******************************************************************************
 * Types                                                                      *
 ******************************************************************************/

/******************************************************************************
 * Private functions                                                          *
 ******************************************************************************/

template<typename G>
std::map<typename boost::graph_traits<G>::vertex_descriptor, unsigned> arriving_times( const typename boost::graph_traits<G>::vertex_descriptor& node,
                                                                                       const G& graph )
{
  std::stack<std::pair<typename boost::graph_traits<G>::vertex_descriptor, unsigned>> stack;
  std::map<typename boost::graph_traits<G>::vertex_descriptor, unsigned> times;

  stack.push( {node, 0u} );

  while ( !stack.empty() )
  {
    auto top = stack.top(); stack.pop();

    if ( boost::out_degree( top.first, graph ) == 0u )
    {
      if ( top.first != 0u )
      {
        if ( times.find( top.first ) == times.end() || times[top.first] > top.second )
        {
          times[top.first] = top.second;
        }
      }
    }
    else
    {
      for ( const auto& child : boost::make_iterator_range( boost::adjacent_vertices( top.first, graph ) ) )
      {
        stack.push( {child, top.second + 1u} );
      }
    }
  }

  return times;
}

/******************************************************************************
 * Public functions                                                           *
 ******************************************************************************/

depth_command::depth_command( const environment::ptr& env )
  : aig_mig_command( env, "Various depth related operations", "Depth of %s" )
{
  opts.add_options()
    ( "arriving,r", "Compute arriving time of PIs" )
    ;
}

bool depth_command::execute_aig()
{
  if ( is_set( "arriving" ) )
  {
    arriving.clear();
    for ( const auto& output : aig_info().outputs )
    {
      const auto times = arriving_times( output.first.node, aig() );
      std::cout << boost::format( "[i] arriving times at %s" ) % output.second << std::endl;

      std::vector<int> pis;
      for ( auto pi : aig_info().inputs )
      {
        const auto it = times.find( pi );
        if ( it != times.end() )
        {
          std::cout << boost::format( "[i] - %s : %d" ) % aig_info().node_names.at( it->first ) % it->second << std::endl;
          pis.push_back( it->second );
        }
        else
        {
          pis.push_back( -1 );
        }
      }
      arriving.push_back( pis );
    }
  }

  return true;
}

bool depth_command::execute_mig()
{
  if ( is_set( "arriving" ) )
  {
    arriving.clear();
    for ( const auto& output : mig_info().outputs )
    {
      const auto times = arriving_times( output.first.node, mig() );
      std::cout << boost::format( "[i] arriving times at %s" ) % output.second << std::endl;

      std::vector<int> pis;
      for ( auto pi : mig_info().inputs )
      {
        const auto it = times.find( pi );
        if ( it != times.end() )
        {
          std::cout << boost::format( "[i] - %s : %d" ) % mig_info().node_names.at( it->first ) % it->second << std::endl;
          pis.push_back( it->second );
        }
        else
        {
          pis.push_back( -1 );
        }
      }
      arriving.push_back( pis );
    }
  }

  return true;
}

command::log_opt_t depth_command::log() const
{
  if ( is_set( "arriving" ) )
  {
    return log_opt_t({{"arriving", arriving}});
  }
  else
  {
    return boost::none;
  }
}

}

// Local Variables:
// c-basic-offset: 2
// eval: (c-set-offset 'substatement-open 0)
// eval: (c-set-offset 'innamespace 0)
// End:
