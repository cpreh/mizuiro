//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_HOMOGENOUS_STATIC_NS_TAG_OF_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_HOMOGENOUS_STATIC_NS_TAG_OF_HPP_INCLUDED

#include <mizuiro/color/format/homogenous_static_fwd.hpp>
#include <mizuiro/color/format/tag_of_fwd.hpp>
#include <mizuiro/color/format/homogenous_static_ns/tag.hpp>


namespace mizuiro
{
namespace color
{
namespace format
{

template<
	typename ChannelType,
	typename Layout
>
struct
tag_of<
	mizuiro::color::format::homogenous_static<
		ChannelType,
		Layout
	>
>
{
	typedef
	mizuiro::color::format::homogenous_static_ns::tag<
		mizuiro::color::format::homogenous_static<
			ChannelType,
			Layout
		>
	>
	type;
};

}
}
}

#endif
