#ifndef MIZUIRO_IMAGE_DETAIL_RAW_ACCESS_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_RAW_ACCESS_HPP_INCLUDED

#include <mizuiro/image/detail/stride_pointer_impl.hpp>
#include <mizuiro/color/channel_proxy_impl.hpp>
#include <mizuiro/detail/apply_const.hpp>
#include <mizuiro/detail/index_of.hpp>
#include <boost/mpl/size.hpp>

namespace mizuiro
{
namespace image
{
namespace detail
{

template<
	typename Layout,
	typename Pointer
>
struct raw_access {
	typedef typename Layout:: template replace_access<
		raw_access<
			Layout,
			Pointer
		>
	>::type layout;

	typedef typename Layout::channel_type channel_type;

	template<
		typename Channel,
		typename Constness
	>
	struct channel_reference {
		typedef color::channel_proxy<
			layout,
			Channel,
			Constness
		> type;
	};

	template<
		typename Constness
	>
	struct pointer {
		typedef stride_pointer<
			typename mizuiro::detail::apply_const<
				Pointer,
				Constness
			>::type,
			boost::mpl::size<
				typename Layout::layout::order
			>::value
		> type;
	};

	template<
		typename Channel
	>
	struct channel_value_type {
		typedef channel_type type;
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
			return ptr + 
				mizuiro::detail::index_of<
					typename Layout::layout::order,
					Channel
				>::value
			;
		}
	};
};

}
}
}

#endif
