//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_INIT_DETAIL_TRAMPOLINE_HPP_INCLUDED
#define MIZUIRO_COLOR_INIT_DETAIL_TRAMPOLINE_HPP_INCLUDED

#include <mizuiro/color/init/detail/channel_value.hpp>
#include <mizuiro/color/init/detail/channel_percentage.hpp>
#include <mizuiro/color/init/detail/make_values.hpp>
#include <mizuiro/color/init/detail/values.hpp>
#include <boost/fusion/container/generation/make_vector.hpp>
#include <boost/fusion/container/vector/vector.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_floating_point.hpp>

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
	detail::values<
		boost::fusion::vector1<
			color::init::detail::channel_value<
				Value,
				Channel
			>
		>
	> const
	operator=(
		Value const &_value
	) const
	{
		return
			detail::make_values(
				boost::fusion::make_vector(
					color::init::detail::channel_value<
						Value,
						Channel
					>(
						_value,
						Channel()
					)
				)
			);
	}

	template<
		typename Value
	>
	typename boost::enable_if<
		boost::is_floating_point<
			Value
		>,
		detail::values<
			boost::fusion::vector1<
				color::init::detail::channel_percentage<
					Value,
					Channel
				>
			>
		> const
	>::type
	operator%=(
		Value const &_value
	) const
	{
		return
			detail::make_values(
				boost::fusion::make_vector(
					color::init::detail::channel_percentage<
						Value,
						Channel
					>(
						_value,
						Channel()
					)
				)
			);
	}
};

}
}
}
}

#endif
