//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_DETAIL_PROMOTE_TYPE_HPP_INCLUDED
#define MIZUIRO_DETAIL_PROMOTE_TYPE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace mizuiro::detail
{

template <typename Type>
using promote_type = decltype(+std::declval<Type>());

}

#endif
