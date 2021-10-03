//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_COMPATIBLE_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_COMPATIBLE_HPP_INCLUDED

#include <mizuiro/color/format/same_channel_value_types.hpp>
#include <mizuiro/color/format/same_channels.hpp>
#include <mizuiro/color/format/same_spaces.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace mizuiro::color::format
{

/**
\brief Tests whether two color formats are statically compatible

Two sformats are compatible iff
<ul>
<li>they use the same color space, </li>
<li>their sets of static channels are the same and</li>
<li>for every channel their channel value types are the same.</li>
</ul>

Intuitively, colors of two compatible formats can be converted into each other
by copying each channel individually.
*/
template<
	typename Format1,
	typename Format2
>
using compatible
=
std::conjunction<
	mizuiro::color::format::same_spaces<
		Format1,
		Format2
	>,
	mizuiro::color::format::same_channels<
		Format1,
		Format2
	>,
	mizuiro::color::format::same_channel_value_types<
		Format1,
		Format2
	>
>;

}

#endif
