//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_CANONICAL_NS_TAG_OF_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_CANONICAL_NS_TAG_OF_HPP_INCLUDED

#include <mizuiro/image/format/canonical_fwd.hpp>
#include <mizuiro/image/format/tag_of_fwd.hpp>
#include <mizuiro/image/format/canonical_ns/tag.hpp>


namespace mizuiro
{
namespace image
{
namespace format
{

template<
	typename DimType,
	typename Type
>
struct
tag_of<
	mizuiro::image::format::canonical<
		DimType,
		Type
	>
>
{
	using
	type
	=
	mizuiro::image::format::canonical_ns::tag<
		mizuiro::image::format::canonical<
			DimType,
			Type
		>
	>;
};

}
}
}

#endif
