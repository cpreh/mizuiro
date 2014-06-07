//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_INIT_DETAIL_TRAMPOLINE_HPP_INCLUDED
#define MIZUIRO_COLOR_INIT_DETAIL_TRAMPOLINE_HPP_INCLUDED

#include <mizuiro/color/init/detail/channel_percentage.hpp>
#include <mizuiro/color/init/detail/channel_value.hpp>
#include <mizuiro/color/init/detail/make_values.hpp>
#include <mizuiro/color/init/detail/values.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/fusion/container/generation/make_vector.hpp>
#include <boost/fusion/container/vector/vector.hpp>
#include <boost/type_traits/is_floating_point.hpp>
#include <boost/utility/enable_if.hpp>
#include <mizuiro/detail/external_end.hpp>


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
	inline
	mizuiro::color::init::detail::values<
		boost::fusion::vector1<
			mizuiro::color::init::detail::channel_value<
				Value,
				Channel
			>
		>
	> const
	operator=(
		Value const &_value
	) const
	{
MIZUIRO_DETAIL_IGNORE_EFFCPP
		return
			mizuiro::color::init::detail::make_values(
				boost::fusion::make_vector(
					mizuiro::color::init::detail::channel_value<
						Value,
						Channel
					>(
						_value,
						Channel()
					)
				)
			);
MIZUIRO_DETAIL_POP_WARNING
	}

	template<
		typename Value
	>
	inline
	typename
	boost::enable_if<
		boost::is_floating_point<
			Value
		>,
		mizuiro::color::init::detail::values<
			boost::fusion::vector1<
				mizuiro::color::init::detail::channel_percentage<
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
MIZUIRO_DETAIL_IGNORE_EFFCPP
		return
			mizuiro::color::init::detail::make_values(
				boost::fusion::make_vector(
					mizuiro::color::init::detail::channel_percentage<
						Value,
						Channel
					>(
						_value,
						Channel()
					)
				)
			);
MIZUIRO_DETAIL_POP_WARNING
	}
};

}
}
}
}

#endif
