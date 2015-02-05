//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_DETAIL_PLANAR_COLOR_NS_POINTER_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_DETAIL_PLANAR_COLOR_NS_POINTER_HPP_INCLUDED

#include <mizuiro/array.hpp>
#include <mizuiro/color/types/pointer.hpp>
#include <mizuiro/color/types/pointer_ns/tag.hpp>
#include <mizuiro/image/format/detail/planar_color_ns/tag.hpp>


namespace mizuiro
{
namespace color
{
namespace types
{
namespace pointer_ns
{

template<
	typename Access,
	typename Format,
	typename Constness
>
mizuiro::array<
	mizuiro::color::types::pointer<
		Access,
		typename
		Format::base,
		Constness
	>,
	Format::base::element_count
>
pointer_adl(
	mizuiro::color::types::pointer_ns::tag,
	Access,
	mizuiro::image::format::detail::planar_color_ns::tag<
		Format
	>,
	Constness
);

}
}
}
}

#endif
