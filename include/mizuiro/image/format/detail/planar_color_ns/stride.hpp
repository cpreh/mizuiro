//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_DETAIL_PLANAR_COLOR_NS_STRIDE_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_DETAIL_PLANAR_COLOR_NS_STRIDE_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <mizuiro/color/access/stride.hpp>
#include <mizuiro/color/access/stride_ns/tag.hpp>
#include <mizuiro/color/format/store_fwd.hpp>
#include <mizuiro/image/format/detail/planar_color_ns/tag.hpp>


namespace mizuiro
{
namespace color
{
namespace access
{
namespace stride_ns
{

template<
	typename Access,
	typename Format
>
mizuiro::size_type
stride_adl(
	mizuiro::color::access::stride_ns::tag,
	Access,
	mizuiro::image::format::detail::planar_color_ns::tag<
		Format
	>,
	mizuiro::color::format::store<
		Format
	> const &_format_store
)
{
	return
		mizuiro::color::access::stride<
			Access
		>(
			_format_store
		)
		/
		Format::base::element_count
		;
}

}
}
}
}

#endif
