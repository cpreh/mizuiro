#ifndef MIZUIRO_IMAGE_RAW_VIEW_HPP_INCLUDED
#define MIZUIRO_IMAGE_RAW_VIEW_HPP_INCLUDED

#include <mizuiro/image/view_impl.hpp>
#include <mizuiro/image/detail/raw_access.hpp>
#include <mizuiro/detail/constness_from_pointer.hpp>

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
		typename Format::template replace_access<
			detail::raw_access<
				typename Format::image_format::color_format,
				Pointer
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
