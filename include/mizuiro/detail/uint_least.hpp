//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_UINT_LEAST_HPP_INCLUDED
#define MIZUIRO_DETAIL_UINT_LEAST_HPP_INCLUDED

#include <mizuiro/detail/bit_count.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/find.hpp>
#include <boost/mpl/greater_equal.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <cstdint>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace detail
{

template<
	typename Bits
>
using uint_least
=
boost::mpl::deref<
	typename boost::mpl::find_if<
		boost::mpl::vector4<
			std::uint8_t,
			std::uint16_t,
			std::uint32_t,
			std::uint64_t
		>,
		boost::mpl::greater_equal<
			mizuiro::detail::bit_count<
				boost::mpl::_1
			>,
			Bits
		>
	>::type
>;

}
}

#endif
