#ifndef MIZUIRO_COLOR_DETAIL_NORMAL_ACCESS_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_NORMAL_ACCESS_HPP_INCLUDED

#include <mizuiro/detail/apply_const.hpp>
#include <mizuiro/detail/index_of.hpp>

namespace mizuiro
{
namespace color
{
namespace detail
{

template<
	typename ChannelType,
	typename Layout
>
struct normal_access {
	typedef ChannelType channel_type;

	template<
		typename Channel,
		typename Constness
	>
	struct channel_reference {
		typedef typename mizuiro::detail::apply_const<
			channel_type &,
			Constness
		>::type type;
	};

	template<
		typename Channel
	>
	struct channel_value_type {
		typedef ChannelType type;
	};

	template<
		typename Constness
	>
	struct pointer {
		typedef typename mizuiro::detail::apply_const<
			channel_type *,
			Constness
		>::type type;
	};

	template<
		typename Channel,
		typename Constness
	>
	struct extract_channel {
		static
		typename channel_reference<
			Channel,
			Constness
		>::type
		execute(
			typename pointer<
				Constness
			>::type const ptr
		)
		{
			return ptr[
				mizuiro::detail::index_of<
					typename Layout::order,
					Channel
				>::value
			];
		}
	};
};

}
}
}

#endif
