//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_HOMOGENOUS_DYNAMIC_NS_TAG_OF_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_HOMOGENOUS_DYNAMIC_NS_TAG_OF_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <mizuiro/color/format/homogenous_dynamic_fwd.hpp>
#include <mizuiro/color/format/tag_of_fwd.hpp>
#include <mizuiro/color/format/homogenous_dynamic_ns/tag.hpp>


namespace mizuiro
{
namespace color
{
namespace format
{

template<
	typename ChannelType,
	typename Space,
	mizuiro::size_type ChannelCount
>
struct
tag_of<
	mizuiro::color::format::homogenous_dynamic<
		ChannelType,
		Space,
		ChannelCount
	>
>
{
	typedef
	mizuiro::color::format::homogenous_dynamic_ns::tag<
		mizuiro::color::format::homogenous_dynamic<
			ChannelType,
			Space,
			ChannelCount
		>
	>
	type;
};

}
}
}

#endif
