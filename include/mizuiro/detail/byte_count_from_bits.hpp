//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_BYTE_COUNT_FROM_BITS_HPP_INCLUDED
#define MIZUIRO_DETAIL_BYTE_COUNT_FROM_BITS_HPP_INCLUDED

#include <mizuiro/raw_value.hpp>
#include <mizuiro/size_type.hpp>
#include <mizuiro/detail/bit_count.hpp>


namespace mizuiro
{
namespace detail
{

template<
	typename Bits
>
struct byte_count_from_bits
{
	static mizuiro::size_type const bits =
		mizuiro::detail::bit_count<
			mizuiro::raw_value
		>::value;

	static mizuiro::size_type const value =
		(
			Bits::value % bits == 0u
		)
		?
			Bits::value / bits
		:
			Bits::value / bits + 1u
		;
};

}
}

#endif
