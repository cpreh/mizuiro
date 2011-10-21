//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_OPERATORS_DETAIL_COMPARE_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_OPERATORS_DETAIL_COMPARE_CHANNEL_HPP_INCLUDED

#include <mizuiro/compare.hpp>
#include <mizuiro/color/detail/unwrap_channel.hpp>


namespace mizuiro
{
namespace color
{
namespace operators
{
namespace detail
{

template<
	typename T1,
	typename T2
>
bool
compare_channel(
	T1 const &_t1,
	T2 const &_t2
)
{
	return
		::mizuiro::compare(
			color::detail::unwrap_channel(
				_t1
			),
			color::detail::unwrap_channel(
				_t2
			)
		);
}

}
}
}
}

#endif
