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
 * @file read_bench.hpp
 *
 * @brief Read bench circuit into an AIG
 *
 * @author Heinz Riener
 * @author Mathias Soeken
 *
 * @since  2.0
 */

#ifndef READ_BENCH_HPP
#define READ_BENCH_HPP

#include <classical/aig.hpp>
#include <classical/netlist_graphs.hpp>

#include <iostream>
#include <string>

namespace cirkit
{

void read_bench( aig_graph& aig, std::ifstream& is );
void read_bench( aig_graph& aig, const std::string& filename );

void read_bench( lut_graph_t& aig, const std::string& filename );

}

#endif

// Local Variables:
// c-basic-offset: 2
// eval: (c-set-offset 'substatement-open 0)
// eval: (c-set-offset 'innamespace 0)
// End:
