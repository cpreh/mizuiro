//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_TYPES_NEEDS_PREPARE_HPP_INCLUDED
#define MIZUIRO_IMAGE_TYPES_NEEDS_PREPARE_HPP_INCLUDED

#include <mizuiro/image/format/make_tag_of.hpp>
#include <mizuiro/image/types/needs_prepare_ns/tag.hpp>


namespace mizuiro::image::types
{

template<
	typename Format
>
using
needs_prepare
=
decltype(
	needs_prepare_adl(
		mizuiro::image::types::needs_prepare_ns::tag(),
		mizuiro::image::format::make_tag_of<
			Format
		>()
	)
);

}

#endif
