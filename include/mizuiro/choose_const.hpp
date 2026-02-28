//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_CHOOSE_CONST_HPP_INCLUDED
#define MIZUIRO_CHOOSE_CONST_HPP_INCLUDED

#include <mizuiro/detail/choose_const.hpp>

namespace mizuiro
{

template <typename Constness, typename NonConst, typename Const>
using choose_const = mizuiro::detail::choose_const<Constness, NonConst, Const>::type;

}

#endif
