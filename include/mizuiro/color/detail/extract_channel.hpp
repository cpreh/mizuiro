#ifndef MIZUIRO_COLOR_DETAIL_EXTRACT_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_EXTRACT_CHANNEL_HPP_INCLUDED

#include <mizuiro/color/detail/channel_ref.hpp>
#include <mizuiro/detail/index_of.hpp>
#include <mizuiro/detail/apply_const.hpp>

namespace mizuiro
{
namespace color
{
namespace detail
{

template<
	typename Layout,
	typename Channel,
	typename Constness
>
struct extract_channel {
	typedef typename channel_ref<
		Layout,
		Channel,
		Constness
	>::type reference;

	typedef typename mizuiro::detail::apply_const<
		typename Layout::pointer,
		Constness
	>::type pointer;

	static reference
	execute(
		pointer const ptr
	)
	{
		return ptr[
			mizuiro::detail::index_of<
				typename Layout::layout::order,
				Channel
			>::value
		];
	}
};

}
}
}

#endif
