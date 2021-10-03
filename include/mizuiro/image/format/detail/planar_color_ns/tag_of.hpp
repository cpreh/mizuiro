//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_DETAIL_PLANAR_COLOR_NS_TAG_OF_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_DETAIL_PLANAR_COLOR_NS_TAG_OF_HPP_INCLUDED

#include <mizuiro/color/format/tag_of_fwd.hpp>
#include <mizuiro/image/format/detail/planar_color_fwd.hpp>
#include <mizuiro/image/format/detail/planar_color_ns/tag.hpp>


namespace mizuiro::color::format
{

template<
	typename Format
>
struct
tag_of<
	mizuiro::image::format::detail::planar_color<
		Format
	>
>
{
	using
	type
	=
	mizuiro::image::format::detail::planar_color_ns::tag<
		mizuiro::image::format::detail::planar_color<
			Format
		>
	>;
};

}

#endif
