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
 * @file exorcism_minimization.hpp
 *
 * @brief ESOP minimization using EXORCISM-4
 *
 * @author Mathias Soeken
 * @since  2.0
 */

#ifndef EXORCISM_MINIMIZATION_HPP
#define EXORCISM_MINIMIZATION_HPP

// TODO move common types in separate header
#include <classical/optimization/optimization.hpp>

#include <string>

#include <cudd.h>

#include <core/cube.hpp>
#include <core/properties.hpp>

namespace cirkit
{

/**
 * @brief ESOP minimization with EXORCISM-4
 *
 * The BDD will first be written to a PLA file.
 *
 * @author Mathias Soeken
 */
void exorcism_minimization( DdManager * cudd, DdNode * f,
                            const properties::ptr& settings = properties::ptr(),
                            const properties::ptr& statistics = properties::ptr() );

/**
 * @brief ESOP minimization with EXORCISM-4
 *
 * @author Mathias Soeken
 */
void exorcism_minimization( const std::string& filename,
                            const properties::ptr& settings = properties::ptr(),
                            const properties::ptr& statistics = properties::ptr() );

void exorcism_minimization( const cube_vec_t& cubes,
                            const properties::ptr& settings = properties::ptr(),
                            const properties::ptr& statistics = properties::ptr() );

dd_based_esop_optimization_func dd_based_exorcism_minimization_func( properties::ptr settings = std::make_shared<properties>(),
                                                                     properties::ptr statistics = std::make_shared<properties>() );

pla_based_esop_optimization_func pla_based_exorcism_minimization_func( properties::ptr settings = std::make_shared<properties>(),
                                                                       properties::ptr statistics = std::make_shared<properties>() );

}

#endif

// Local Variables:
// c-basic-offset: 2
// eval: (c-set-offset 'substatement-open 0)
// eval: (c-set-offset 'innamespace 0)
// End:
