//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_DETAIL_BYTE_COUNT_FROM_BITS_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_BYTE_COUNT_FROM_BITS_HPP_INCLUDED

#include <mizuiro/integral_size.hpp>
#include <mizuiro/raw_value.hpp>
#include <mizuiro/size_type.hpp>
#include <mizuiro/detail/bit_count.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/mpl/accumulate.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/plus.hpp>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace detail
{

template<
	typename Bits
>
struct byte_count_from_bits
{
	typedef typename boost::mpl::accumulate<
		Bits,
		typename mizuiro::integral_size<
			0u
		>::type,
		boost::mpl::plus<
			boost::mpl::_1,
			boost::mpl::_2
		>
	>::type total_bits;

	static mizuiro::size_type const bits =
		mizuiro::detail::bit_count<
			mizuiro::raw_value
		>::value;

	static mizuiro::size_type const value =
		(
			total_bits::value % bits == 0u
		)
		?
			total_bits::value / bits
		:
			total_bits::value / bits + 1u
		;
};

}
}
}

#endif
