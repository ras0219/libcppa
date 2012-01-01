/******************************************************************************\
 *           ___        __                                                    *
 *          /\_ \    __/\ \                                                   *
 *          \//\ \  /\_\ \ \____    ___   _____   _____      __               *
 *            \ \ \ \/\ \ \ '__`\  /'___\/\ '__`\/\ '__`\  /'__`\             *
 *             \_\ \_\ \ \ \ \L\ \/\ \__/\ \ \L\ \ \ \L\ \/\ \L\.\_           *
 *             /\____\\ \_\ \_,__/\ \____\\ \ ,__/\ \ ,__/\ \__/.\_\          *
 *             \/____/ \/_/\/___/  \/____/ \ \ \/  \ \ \/  \/__/\/_/          *
 *                                          \ \_\   \ \_\                     *
 *                                           \/_/    \/_/                     *
 *                                                                            *
 * Copyright (C) 2011, 2012                                                   *
 * Dominik Charousset <dominik.charousset@haw-hamburg.de>                     *
 *                                                                            *
 * This file is part of libcppa.                                              *
 * libcppa is free software: you can redistribute it and/or modify it under   *
 * the terms of the GNU Lesser General Public License as published by the     *
 * Free Software Foundation, either version 3 of the License                  *
 * or (at your option) any later version.                                     *
 *                                                                            *
 * libcppa is distributed in the hope that it will be useful,                 *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                       *
 * See the GNU Lesser General Public License for more details.                *
 *                                                                            *
 * You should have received a copy of the GNU Lesser General Public License   *
 * along with libcppa. If not, see <http://www.gnu.org/licenses/>.            *
\******************************************************************************/


#ifndef CPPA_UTIL_A_MATCHES_B_HPP
#define CPPA_UTIL_A_MATCHES_B_HPP

/*
#include <type_traits>

#include "cppa/any_type.hpp"
#include "cppa/util/void_type.hpp"
#include "cppa/util/type_list.hpp"
#include "cppa/util/is_one_of.hpp"
#include "cppa/util/conjunction.hpp"

namespace cppa { namespace detail {

template<typename HeadA, typename TailA, typename HeadB, typename TailB>
struct amb_helper : util::conjunction<util::is_one_of<HeadA, HeadB, any_type>,
                                      amb_helper<typename TailA::head_type,
                                                 typename TailA::tail_type,
                                                 typename TailB::head_type,
                                                 typename TailB::tail_type>>
{
    static_assert(   std::is_same<HeadB, any_type>::value == false
                  && std::is_same<HeadB, any_type*>::value == false,
                  "any_type in right hand type list");
};

template<>
struct amb_helper<util::void_type, util::type_list<>,
                  util::void_type, util::type_list<>> : std::true_type
{
};

template<typename TailA>
struct amb_helper<any_type*, TailA, util::void_type, util::type_list<>>
    : amb_helper<typename TailA::head_type,
                 typename TailA::tail_type,
                 util::void_type,
                 util::type_list<>>
{
};

template<typename TailA, typename HeadB, typename TailB>
struct amb_helper<any_type*, TailA, HeadB, TailB>
    : util::disjunction<amb_helper<typename TailA::head_type,
                                   typename TailA::tail_type,
                                   HeadB,
                                   TailB>,
                        amb_helper<any_type*,
                                   TailA,
                                   typename TailB::head_type,
                                   typename TailB::tail_type>>
{
    static_assert(std::is_same<HeadB, any_type>::value == false,
                  "any_type in right hand type list");
};

} } // namespace cppa::detail

namespace cppa { namespace util {

template<typename ListA, typename ListB>
struct a_matches_b : detail::amb_helper<typename ListA::head_type,
                                        typename ListA::tail_type,
                                        typename ListB::head_type,
                                        typename ListB::tail_type>
{
};

} } // namespace cppa::util
*/

#endif // CPPA_UTIL_A_MATCHES_B_HPP
