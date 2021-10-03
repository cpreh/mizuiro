//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_DETAIL_PLANAR_COLOR_NS_TYPES_POINTER_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_DETAIL_PLANAR_COLOR_NS_TYPES_POINTER_HPP_INCLUDED

#include <mizuiro/color/types/pointer.hpp>
#include <mizuiro/color/types/pointer_ns/tag.hpp>
#include <mizuiro/image/format/detail/planar_color_ns/tag.hpp>
#include <fcppt/array/object_impl.hpp>


namespace mizuiro::color::types::pointer_ns
{

template<
	typename Access,
	typename Format,
	typename Constness
>
fcppt::array::object<
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

#endif
