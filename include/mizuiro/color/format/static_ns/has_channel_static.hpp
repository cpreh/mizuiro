//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_STATIC_NS_HAS_CHANNEL_STATIC_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_STATIC_NS_HAS_CHANNEL_STATIC_HPP_INCLUDED

#include <mizuiro/color/format/static_ns/tag.hpp>
#include <mizuiro/color/types/has_channel_static_ns/tag.hpp>
#include <mizuiro/mpl/bool.hpp>
#include <mizuiro/mpl/contains.hpp>


namespace mizuiro
{
namespace color
{
namespace types
{
namespace has_channel_static_ns
{

template<
	typename Format,
	typename Channel
>
mizuiro::mpl::bool_<
	mizuiro::mpl::contains<
		typename Format::layout::order,
		Channel
	>()
>
has_channel_static_adl(
	mizuiro::color::types::has_channel_static_ns::tag,
	mizuiro::color::format::static_ns::tag<
		Format
	>,
	Channel
);

}
}
}
}

#endif
