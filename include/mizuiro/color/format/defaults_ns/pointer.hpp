//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_DEFAULTS_NS_POINTER_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_DEFAULTS_NS_POINTER_HPP_INCLUDED

#include <mizuiro/apply_const.hpp>
#include <mizuiro/raw_pointer.hpp>
#include <mizuiro/access/raw.hpp>
#include <mizuiro/color/format/defaults_ns/tag.hpp>
#include <mizuiro/color/types/pointer_ns/tag.hpp>


namespace mizuiro
{
namespace color
{
namespace types
{
namespace pointer_ns
{

template<
	typename Constness,
	typename Format
>
mizuiro::apply_const<
	typename
	mizuiro::raw_pointer,
	Constness
>
pointer_adl(
	mizuiro::color::types::pointer_ns::tag,
	mizuiro::access::raw,
	mizuiro::color::format::defaults_ns::tag<
		Format
	>,
	Constness
);

}
}
}
}

#endif
