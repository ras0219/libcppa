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


#ifndef IS_ITERABLE_HPP
#define IS_ITERABLE_HPP

#include "cppa/util/is_primitive.hpp"
#include "cppa/util/is_forward_iterator.hpp"

namespace cppa { namespace util {

template<typename T>
class is_iterable
{

    // this horrible code would just disappear if we had concepts
    template<class C>
    static bool sfinae_fun
    (
        C const* cc,
        // check for 'C::begin()' returning a forward iterator
        typename util::enable_if<util::is_forward_iterator<decltype(cc->begin())>>::type* = 0,
        // check for 'C::end()' returning the same kind of forward iterator
        typename util::enable_if<std::is_same<decltype(cc->begin()), decltype(cc->end())>>::type* = 0
    )
    {
        return true;
    }

    // SFNINAE default
    static void sfinae_fun(...) { }

    typedef decltype(sfinae_fun(static_cast<T const*>(nullptr))) result_type;

 public:

    static const bool value =    util::is_primitive<T>::value == false
                              && std::is_same<bool, result_type>::value;

};

} } // namespace cppa::util

#endif // IS_ITERABLE_HPP
