#ifndef MIZUIRO_COLOR_INIT_DETAIL_TRAMPOLINE_HPP_INCLUDED
#define MIZUIRO_COLOR_INIT_DETAIL_TRAMPOLINE_HPP_INCLUDED

#include <mizuiro/color/detail/init_channel.hpp>
#include <mizuiro/color/detail/init_channel_percentage.hpp>
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
struct trampoline {
	template<
		typename Value
	>
	color::detail::init_channel<
		Value,
		Channel
	> const
	operator=(
		Value const &value
	) const
	{
		return color::detail::init_channel<
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
		color::detail::init_channel_percentage<
			Value,
			Channel
		> const
	>::type
	operator %=(
		Value const &value
	) const
	{
		return color::detail::init_channel_percentage<
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
