//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_DEFAULTS_NS_ADVANCE_POINTER_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_DEFAULTS_NS_ADVANCE_POINTER_HPP_INCLUDED

#include <mizuiro/difference_type.hpp>
#include <mizuiro/color/access/advance_pointer_ns/tag.hpp>
#include <mizuiro/color/format/store_fwd.hpp>
#include <mizuiro/color/format/defaults_ns/tag.hpp>
#include <mizuiro/color/types/pointer.hpp>


namespace mizuiro
{
namespace color
{
namespace access
{
namespace advance_pointer_ns
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
advance_pointer_adl(
	mizuiro::color::access::advance_pointer_ns::tag,
	mizuiro::color::format::defaults_ns::tag<
		Format
	>,
	Access,
	Constness,
	mizuiro::color::format::store<
		Format
	> const &,
	mizuiro::color::types::pointer<
		Access,
		Format,
		Constness
	> const _pointer,
	mizuiro::difference_type const _diff
)
{
	return
		_pointer
		+
		_diff;
}

}
}
}
}

#endif
