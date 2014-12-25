//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_DYNAMIC_NS_LAYOUT_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_DYNAMIC_NS_LAYOUT_HPP_INCLUDED

#include <mizuiro/color/access/layout_ns/tag.hpp>
#include <mizuiro/color/format/store_fwd.hpp>
#include <mizuiro/color/format/dynamic_ns/tag.hpp>
// TODO: Put this somewhere else!
#include <mizuiro/range/include/array.hpp>


namespace mizuiro
{
namespace color
{
namespace access
{
namespace layout_ns
{

template<
	typename Format
>
typename
Format::layout const &
layout_adl(
	mizuiro::color::access::layout_ns::tag,
	mizuiro::color::format::dynamic_ns::tag<
		Format
	>,
	mizuiro::color::format::store<
		Format
	> const &_format
)
{
	return
		_format.get()->order;
}

}
}
}
}

#endif
