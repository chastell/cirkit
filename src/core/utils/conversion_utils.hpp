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

/**
 * @file conversion_utils.hpp
 *
 * @brief Some helper functions for conversion
 *
 * @author Mathias Soeken
 * @author Heinz Riener
 * @since  2.1
 */

#ifndef CONVERSION_UTILS_HPP
#define CONVERSION_UTILS_HPP

#include <string>

namespace cirkit
{

char convert_bin2hex( const std::string& bits );
std::string convert_hex2bin( const char& hex );
std::string convert_hex2bin( const std::string& hex );

}

#endif

// Local Variables:
// c-basic-offset: 2
// eval: (c-set-offset 'substatement-open 0)
// eval: (c-set-offset 'innamespace 0)
// End:
