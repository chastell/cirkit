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
 * @file bdd_fwd.hpp
 *
 * @brief BDD package forward declarations
 *
 * @author Stefan Frehse
 * @since  2.3
 */
#ifndef BDD_FWD_HPP
#define BDD_FWD_HPP

#include <memory>

namespace cirkit
{

class bdd_manager;
using bdd_manager_ptr  = std::shared_ptr<bdd_manager>;
using bdd_manager_cptr = std::shared_ptr<const bdd_manager>;

}

#endif

// Local Variables:
// c-basic-offset: 2
// eval: (c-set-offset 'substatement-open 0)
// eval: (c-set-offset 'innamespace 0)
// End:
