//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_DETAIL_BIT_COUNT_HPP_INCLUDED
#define MIZUIRO_DETAIL_BIT_COUNT_HPP_INCLUDED

#include <mizuiro/integral_size.hpp>
#include <fcppt/config/external_begin.hpp>
#include <limits>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace mizuiro::detail
{

template <typename IntType>
struct bit_count : mizuiro::integral_size<std::numeric_limits<IntType>::digits>
{
  static_assert(std::is_unsigned_v<IntType>, "IntType must be unsigned");
};

}

#endif
