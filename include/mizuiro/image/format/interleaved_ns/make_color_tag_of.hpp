//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_INTERLEAVED_NS_MAKE_COLOR_TAG_OF_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_INTERLEAVED_NS_MAKE_COLOR_TAG_OF_HPP_INCLUDED

#include <mizuiro/rebind_tag.hpp>
#include <mizuiro/color/format/make_tag_of.hpp>
#include <mizuiro/image/format/interleaved_ns/color_tag_of_ns/tag.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace mizuiro::image::format::interleaved_ns
{

template<
	typename Type
>
using
make_color_tag_of
=
mizuiro::rebind_tag<
	decltype(
		color_tag_of_adl(
			std::declval<
				mizuiro::image::format::interleaved_ns::color_tag_of_ns::tag
			>(),
			std::declval<
				mizuiro::color::format::make_tag_of<
					typename
					Type::color_format
				>
			>()
		)
	),
	Type
>;

}

#endif
