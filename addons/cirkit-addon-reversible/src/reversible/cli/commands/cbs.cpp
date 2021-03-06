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

#include "cbs.hpp"

#include <boost/format.hpp>

#include <alice/rules.hpp>

#include <core/cli/stores.hpp>
#include <core/utils/program_options.hpp>
#include <classical/cli/stores.hpp>
#include <reversible/cli/stores.hpp>
#include <reversible/synthesis/cut_based_synthesis.hpp>

namespace cirkit
{

/******************************************************************************
 * Types                                                                      *
 ******************************************************************************/

/******************************************************************************
 * Private functions                                                          *
 ******************************************************************************/

/******************************************************************************
 * Public functions                                                           *
 ******************************************************************************/

cbs_command::cbs_command( const environment::ptr& env )
  : cirkit_command( env, "Circuit based synthesis", "[M. Soeken, A. Chattopadhyay: Unlocking Efficiency and Scalability of Reversible Logic Synthesis using Conventional Logic Synthesis, in: DAC 53 (2016)]" )
{
  opts.add_options()
    ( "threshold,t",        value_with_default( &threshold ), "threshold for size of FFRs" )
    ( "embedding",          value_with_default( &embedding ), "0u: BDD-based, 1u: PLA-based" )
    ( "synthesis",          value_with_default( &synthesis ), "0u: TBS (BDD), 1u: TBS (SAT), 2u: DBS" )
    ( "store_intermediate",                                   "stores all intermediate results (BDDs, RCBDDs, and circuits) in store\n"
                                                              "should only be used for debugging purposes on small functions" )
    ;
  add_new_option();
  be_verbose();
}

command::rules_t cbs_command::validity_rules() const
{
  return { has_store_element<aig_graph>( env ) };
}

bool cbs_command::execute()
{
  const auto& aigs = env->store<aig_graph>();
  auto& circuits = env->store<circuit>();

  auto settings = make_settings();

  settings->set( "var_threshold", threshold );
  settings->set( "embedding", embedding );
  settings->set( "synthesis", synthesis );
  settings->set( "store_intermediate", is_set( "store_intermediate" ) );

  circuit circ;
  cut_based_synthesis( circ, aigs.current(), settings, statistics );

  extend_if_new( circuits );
  circuits.current() = circ;

  print_runtime();

  if ( is_set( "store_intermediate" ) )
  {
    auto& bdds   = env->store<bdd_function_t>();
    auto& rcbdds = env->store<rcbdd>();

    for ( const auto& bdd : statistics->get<std::vector<bdd_function_t>>( "bdds" ) )
    {
      bdds.extend();
      bdds.current() = bdd;
    }

    for ( const auto& cf : statistics->get<std::vector<rcbdd>>( "rcbdds" ) )
    {
      rcbdds.extend();
      rcbdds.current() = cf;
    }

    for ( const auto& circ : statistics->get<std::vector<circuit>>( "circuits" ) )
    {
      circuits.extend();
      circuits.current() = circ;
    }
  }

  return true;
}

command::log_opt_t cbs_command::log() const
{
  return log_opt_t({
      {"runtime",   statistics->get<double>( "runtime" )},
      {"threshold", static_cast<int>(threshold)},
      {"embedding", static_cast<int>(embedding)},
      {"synthesis", static_cast<int>(synthesis)}
    });
}

}

// Local Variables:
// c-basic-offset: 2
// eval: (c-set-offset 'substatement-open 0)
// eval: (c-set-offset 'innamespace 0)
// End:
