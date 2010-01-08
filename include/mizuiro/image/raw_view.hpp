#ifndef MIZUIRO_IMAGE_RAW_VIEW_HPP_INCLUDED
#define MIZUIRO_IMAGE_RAW_VIEW_HPP_INCLUDED

#include <mizuiro/image/view_impl.hpp>
#include <mizuiro/image/detail/raw_access.hpp>
#include <mizuiro/nonconst_tag.hpp>

namespace mizuiro
{
namespace image
{

template<
	typename Format
>
struct raw_view {
	typedef view<
		typename Format::template replace_access<
			detail::raw_access<
				typename Format::image_format::color_format
			>
		>::type,
		mizuiro::nonconst_tag
	> type;
};

}
}

#endif
