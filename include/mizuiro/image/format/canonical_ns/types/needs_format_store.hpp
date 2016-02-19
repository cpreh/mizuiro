//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_CANONICAL_NS_TYPES_NEEDS_FORMAT_STORE_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_CANONICAL_NS_TYPES_NEEDS_FORMAT_STORE_HPP_INCLUDED

#include <mizuiro/image/format/canonical_ns/tag.hpp>
#include <mizuiro/image/types/needs_format_store_ns/tag.hpp>
#include <mizuiro/mpl/false.hpp>


namespace mizuiro
{
namespace image
{
namespace types
{
namespace needs_format_store_ns
{

template<
	typename ImageFormat
>
mizuiro::mpl::false_
needs_format_store_adl(
	mizuiro::image::types::needs_format_store_ns::tag,
	mizuiro::image::format::canonical_ns::tag<
		ImageFormat
	>
);

}
}
}
}

#endif
