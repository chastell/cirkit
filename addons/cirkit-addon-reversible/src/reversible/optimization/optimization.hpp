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
 * @file optimization.hpp
 *
 * @brief General Optimization type definitions
 *
 * @author Mathias Soeken
 * @since  1.0
 */

#ifndef OPTIMIZATION_HPP
#define OPTIMIZATION_HPP

#include <boost/function.hpp>

#include <core/functor.hpp>
#include <reversible/circuit.hpp>

namespace cirkit
{

  /**
   * @brief Optimization functor
   *
   * @since 1.0
   */
  typedef functor<bool(circuit&, const circuit&)> optimization_func;

}

#endif /* OPTIMIZATION_HPP */

// Local Variables:
// c-basic-offset: 2
// eval: (c-set-offset 'substatement-open 0)
// eval: (c-set-offset 'innamespace 0)
// End:
