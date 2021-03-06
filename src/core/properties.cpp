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

#include "properties.hpp"

namespace cirkit
{

  properties::properties()
  {
  }

  const properties::value_type& properties::operator[]( const properties::key_type& k ) const
  {
    return map.find( k )->second;
  }

  void properties::set( const properties::key_type& k, const properties::value_type& value )
  {
    map[k] = value;
  }

  properties::storage_type::const_iterator properties::begin() const
  {
    return map.begin();
  }

  properties::storage_type::const_iterator properties::end() const
  {
    return map.end();
  }

  unsigned properties::size() const
  {
    return map.size();
  }

  void properties::clear()
  {
    map.clear();
  }

  void set_error_message( properties::ptr statistics, const std::string& error )
  {
    if ( statistics )
    {
      statistics->set( "error", error );
    }
  }

}

// Local Variables:
// c-basic-offset: 2
// eval: (c-set-offset 'substatement-open 0)
// eval: (c-set-offset 'innamespace 0)
// End:
