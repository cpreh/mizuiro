#ifndef MIZUIRO_COLOR_DETAIL_HOMOGENOUS_LAYOUT_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_HOMOGENOUS_LAYOUT_HPP_INCLUDED

#include <mizuiro/detail/apply_const.hpp>

namespace mizuiro
{
namespace color
{
namespace detail
{

template<
	typename Reference,
	typename Pointer,
	typename Layout
>
struct homogenous_layout {
	typedef Pointer pointer;

	template<
		typename Channel,
		typename Constness
	>
	struct channel_reference {
		typedef typename mizuiro::detail::apply_const<
			Reference,
			Constness
		>::type type;
	};

	typedef Layout channels;
};

}
}
}

#endif
