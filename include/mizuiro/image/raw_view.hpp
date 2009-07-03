#ifndef MIZUIRO_IMAGE_RAW_VIEW_HPP_INCLUDED
#define MIZUIRO_IMAGE_RAW_VIEW_HPP_INCLUDED

#include <mizuiro/image/detail/stride_pointer_impl.hpp>
#include <mizuiro/image/view_impl.hpp>
#include <mizuiro/detail/constness_from_pointer.hpp>
#include <boost/mpl/size.hpp>

namespace mizuiro
{
namespace image
{

template<
	typename Format,
	typename Pointer
>
struct raw_view {
	typedef view<
		typename Format::template replace_pointer<
			detail::stride_pointer<
				Pointer,
				boost::mpl::size<
					typename Format::image_format::color_format::layout::order
				>::value
			>
		>::type,
		typename mizuiro::detail::constness_from_pointer<
			Pointer
		>::type
	> type;
};

}
}

#endif
