//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_INTERLEAVED_NS_TAG_OF_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_INTERLEAVED_NS_TAG_OF_HPP_INCLUDED

#include <mizuiro/image/format/interleaved_fwd.hpp>
#include <mizuiro/image/format/tag_of_fwd.hpp>
#include <mizuiro/image/format/interleaved_ns/tag.hpp>


namespace mizuiro::image::format
{

template<
	typename DimType,
	typename ColorFormat
>
struct
tag_of<
	mizuiro::image::format::interleaved<
		DimType,
		ColorFormat
	>
>
{
	using
	type
	=
	mizuiro::image::format::interleaved_ns::tag<
		mizuiro::image::format::interleaved<
			DimType,
			ColorFormat
		>
	>;
};

}

#endif
