#ifndef MIZUIRO_IMAGE_DETAIL_RAW_VIEW_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_RAW_VIEW_HPP_INCLUDED

#include <mizuiro/image/detail/stride_pointer.hpp>
#include <mizuiro/image/view_impl.hpp>
#include <mizuiro/detail/constness_from_pointer.hpp>
#include <boost/mpl/size.hpp>

namespace mizuiro
{
namespace image
{
namespace detail
{

template<
	template<
		typename,
		typename
	> class Iterator,
	typename Format,
	typename Pointer
>
struct raw_view {
	typedef view<
		Iterator<
			typename Format::image_format::color_format:: template replace_pointer<
				stride_pointer<
					Pointer,
					boost::mpl::size<
						typename Format::image_format::color_format::layout::order
					>::value
				>
			>::type,
			typename mizuiro::detail::constness_from_pointer<
				Pointer
			>::type
		>
	> type;
};

}
}
}

#endif
