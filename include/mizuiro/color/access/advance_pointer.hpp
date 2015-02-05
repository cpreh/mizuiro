//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_ACCESS_ADVANCE_POINTER_HPP_INCLUDED
#define MIZUIRO_COLOR_ACCESS_ADVANCE_POINTER_HPP_INCLUDED

#include <mizuiro/difference_type.hpp>
#include <mizuiro/color/access/advance_pointer_ns/tag.hpp>
#include <mizuiro/color/format/make_tag_of.hpp>
#include <mizuiro/color/format/store_fwd.hpp>
#include <mizuiro/color/format/tag_of_fwd.hpp>
#include <mizuiro/color/types/pointer.hpp>


namespace mizuiro
{
namespace color
{
namespace access
{

template<
	typename Access,
	typename Constness,
	typename Format
>
mizuiro::color::types::pointer<
	Access,
	Format,
	Constness
>
advance_pointer(
	mizuiro::color::format::store<
		Format
	> const &_format,
	mizuiro::color::types::pointer<
		Access,
		Format,
		Constness
	> const _pointer,
	mizuiro::difference_type const _diff
)
{
	return
		advance_pointer_adl(
			mizuiro::color::access::advance_pointer_ns::tag(),
			mizuiro::color::format::make_tag_of<
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
