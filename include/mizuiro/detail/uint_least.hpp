//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_UINT_LEAST_HPP_INCLUDED
#define MIZUIRO_DETAIL_UINT_LEAST_HPP_INCLUDED

#include <mizuiro/detail/bit_count.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/cstdint.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/find.hpp>
#include <boost/mpl/greater_equal.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace detail
{

MIZUIRO_DETAIL_IGNORE_EFFCPP

template<
	typename Bits
>
struct uint_least
:
boost::mpl::deref<
	typename boost::mpl::find_if<
		boost::mpl::vector4<
			boost::uint8_t,
			boost::uint16_t,
			boost::uint32_t,
			boost::uint64_t
		>,
		boost::mpl::greater_equal<
			mizuiro::detail::bit_count<
				boost::mpl::_1
			>,
			Bits
		>
	>::type
>
{
};

MIZUIRO_DETAIL_POP_WARNING

}
}

#endif
