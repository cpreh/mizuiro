//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_STATIC_NS_LAYOUT_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_STATIC_NS_LAYOUT_HPP_INCLUDED

#include <mizuiro/color/access/layout_ns/tag.hpp>
#include <mizuiro/color/format/store_fwd.hpp>
#include <mizuiro/color/format/static_ns/tag.hpp>
// TODO: Put this somewhere else!
#include <mizuiro/range/include/mpl.hpp>


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
inline
constexpr
typename
Format::layout::order const
layout_adl(
	mizuiro::color::access::layout_ns::tag,
	mizuiro::color::format::static_ns::tag<
		Format
	>,
	mizuiro::color::format::store<
		Format
	> const &
)
{
	return
		typename Format::layout::order();
}

}
}
}
}

#endif
