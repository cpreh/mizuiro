//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_DETAIL_PLANAR_COLOR_BASE_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_DETAIL_PLANAR_COLOR_BASE_DECL_HPP_INCLUDED

#include <mizuiro/color/format/base_decl.hpp>
#include <mizuiro/image/format/detail/planar_color.hpp>


namespace mizuiro
{
namespace image
{
namespace format
{
namespace detail
{

template<
	typename ColorFormat
>
using
planar_color_base
=
mizuiro::color::format::base<
	mizuiro::image::format::detail::planar_color<
		ColorFormat
	>
>;

}
}
}
}

#endif
