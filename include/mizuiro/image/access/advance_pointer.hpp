//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ACCESS_ADVANCE_POINTER_HPP_INCLUDED
#define MIZUIRO_IMAGE_ACCESS_ADVANCE_POINTER_HPP_INCLUDED

#include <mizuiro/difference_type.hpp>
#include <mizuiro/image/access/advance_pointer_ns/tag.hpp>
#include <mizuiro/image/format/make_tag_of.hpp>
#include <mizuiro/image/format/store_fwd.hpp>
#include <mizuiro/image/format/tag_of_fwd.hpp>
#include <mizuiro/image/types/pointer.hpp>


namespace mizuiro
{
namespace image
{
namespace access
{

template<
	typename Access,
	typename Constness,
	typename Format
>
mizuiro::image::types::pointer<
	Access,
	Format,
	Constness
>
advance_pointer(
	mizuiro::image::format::store<
		Format
	> const &_format,
	mizuiro::image::types::pointer<
		Access,
		Format,
		Constness
	> const _pointer,
	mizuiro::difference_type const _diff
)
{
	return
		advance_pointer_adl(
			mizuiro::image::access::advance_pointer_ns::tag(),
			mizuiro::image::format::make_tag_of<
				Format
			>(),
			Access(),
			Constness(),
			_format,
			_pointer,
			_diff
		);
}

}
}
}

#endif
