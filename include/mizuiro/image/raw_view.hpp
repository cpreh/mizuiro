#ifndef MIZUIRO_IMAGE_RAW_VIEW_HPP_INCLUDED
#define MIZUIRO_IMAGE_RAW_VIEW_HPP_INCLUDED

#include <mizuiro/image/view_impl.hpp>
#include <mizuiro/color/types/homogenous_raw.hpp>
#include <mizuiro/color/access/homogenous_raw.hpp>
#include <mizuiro/access/raw.hpp>
#include <mizuiro/nonconst_tag.hpp>

namespace mizuiro
{
namespace image
{

template<
	typename Format
>
struct raw_view
{
	typedef view<
		::mizuiro::access::raw,
		Format,
		mizuiro::nonconst_tag
	> type;
};

}
}

#endif
