//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERT_STATIC_IS_RGB_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERT_STATIC_IS_RGB_HPP_INCLUDED

#include <mizuiro/color/channel/blue.hpp>
#include <mizuiro/color/channel/green.hpp>
#include <mizuiro/color/channel/red.hpp>
#include <mizuiro/color/format/has_channel_static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace mizuiro::color::convert_static
{

template<
	typename Format
>
using is_rgb
=
std::disjunction<
	mizuiro::color::format::has_channel_static<
		Format,
		mizuiro::color::channel::red
	>,
	mizuiro::color::format::has_channel_static<
		Format,
		mizuiro::color::channel::green
	>,
	mizuiro::color::format::has_channel_static<
		Format,
		mizuiro::color::channel::blue
	>
>;

}

#endif
