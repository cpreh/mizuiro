#ifndef MIZUIRO_COLOR_INIT_DETAIL_TRAMPOLINE_HPP_INCLUDED
#define MIZUIRO_COLOR_INIT_DETAIL_TRAMPOLINE_HPP_INCLUDED

#include <mizuiro/color/detail/init_channel.hpp>

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
		
};

}
}
}
}

#endif
