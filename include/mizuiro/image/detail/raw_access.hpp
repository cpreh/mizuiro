#ifndef MIZUIRO_IMAGE_DETAIL_RAW_ACCESS_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_RAW_ACCESS_HPP_INCLUDED

#include <mizuiro/image/detail/stride_pointer_impl.hpp>
#include <mizuiro/image/raw_pointer.hpp>
#include <mizuiro/color/channel_proxy_impl.hpp>
#include <mizuiro/detail/apply_const.hpp>
#include <mizuiro/detail/index_of.hpp>
#include <boost/mpl/size.hpp>
#include <boost/tr1/array.hpp>

namespace mizuiro
{
namespace image
{
namespace detail
{

template<
	typename Layout
>
struct raw_access {
	typedef typename Layout:: template replace_access<
		raw_access<
			Layout
		>
	>::type layout;

	typedef std::tr1::array<
		raw_value,
		Layout::element_count
		* sizeof(typename Layout::channel_type)
	> store;

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
				raw_pointer,
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
