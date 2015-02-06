//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_DEFAULTS_NS_ACCESS_POINTER_DIFFERENCE_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_DEFAULTS_NS_ACCESS_POINTER_DIFFERENCE_HPP_INCLUDED

#include <mizuiro/difference_type.hpp>
#include <mizuiro/color/access/pointer_difference_ns/tag.hpp>
#include <mizuiro/color/format/store_fwd.hpp>
#include <mizuiro/color/format/defaults_ns/tag.hpp>
#include <mizuiro/color/types/pointer.hpp>


namespace mizuiro
{
namespace color
{
namespace access
{
namespace pointer_difference_ns
{

template<
	typename Access,
	typename Constness,
	typename Format
>
mizuiro::difference_type
pointer_difference_adl(
	mizuiro::color::access::pointer_difference_ns::tag,
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
	> const _pointer1,
	mizuiro::color::types::pointer<
		Access,
		Format,
		Constness
	> const _pointer2
)
{
	return
		_pointer1
		-
		_pointer2;
}

}
}
}
}

#endif
