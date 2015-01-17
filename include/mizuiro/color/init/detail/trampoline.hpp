//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_INIT_DETAIL_TRAMPOLINE_HPP_INCLUDED
#define MIZUIRO_COLOR_INIT_DETAIL_TRAMPOLINE_HPP_INCLUDED

#include <mizuiro/color/channel/undefined_fwd.hpp>
#include <mizuiro/color/init/detail/channel_percentage.hpp>
#include <mizuiro/color/init/detail/channel_value.hpp>
#include <mizuiro/color/init/detail/make_values.hpp>
#include <mizuiro/color/init/detail/values.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <tuple>
#include <type_traits>
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
	static_assert(
		!std::is_same<
			Channel,
			mizuiro::color::channel::undefined
		>::value,
		"Can't initialize undefined channels"
	);

	template<
		typename Value
	>
	inline
	mizuiro::color::init::detail::values<
		std::tuple<
			mizuiro::color::init::detail::channel_value<
				Value,
				Channel
			>
		>
	>
	operator=(
		Value const &_value
	) const
	{
MIZUIRO_DETAIL_IGNORE_EFFCPP
		return
			mizuiro::color::init::detail::make_values(
				std::make_tuple(
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
	mizuiro::color::init::detail::values<
		std::tuple<
			mizuiro::color::init::detail::channel_percentage<
				Value,
				Channel
			>
		>
	>
	operator%=(
		Value const &_value
	) const
	{
		static_assert(
			std::is_floating_point<
				Value
			>::value,
			"Arguments must be of floating point type for '%=' initialization"
		);

MIZUIRO_DETAIL_IGNORE_EFFCPP
		return
			mizuiro::color::init::detail::make_values(
				std::make_tuple(
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
