//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_INIT_DETAIL_TRAMPOLINE_HPP_INCLUDED
#define MIZUIRO_COLOR_INIT_DETAIL_TRAMPOLINE_HPP_INCLUDED

#include <mizuiro/color/init/detail/channel.hpp>
#include <mizuiro/color/init/detail/channel_percentage.hpp>
#include <boost/type_traits/is_floating_point.hpp>
#include <boost/utility/enable_if.hpp>

namespace mizuiro
{
namespace color
{
namespace init
{
namespace detail
{

template<
	typename Channel
>
struct trampoline
{
	template<
		typename Value
	>
	color::init::detail::channel<
		Value,
		Channel
	> const
	operator=(
		Value const &value
	) const
	{
		return
			color::init::detail::channel<
				Value,
				Channel
			>(
				value
			);
	}

	template<
		typename Value
	>
	typename boost::enable_if<
		boost::is_floating_point<
			Value
		>,
		color::init::detail::channel_percentage<
			Value,
			Channel
		> const
	>::type
	operator %=(
		Value const &value
	) const
	{
		return
			color::init::detail::channel_percentage<
				Value,
				Channel
			>(
				value
			);
	}
};

}
}
}
}

#endif
