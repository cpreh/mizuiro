//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_HOMOGENOUS_STATIC_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_HOMOGENOUS_STATIC_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <mizuiro/color/format/homogenous_static_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <fcppt/config/external_end.hpp>


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
struct homogenous_static
{
	using
	channel_type
	=
	ChannelType;

	using
	layout
	=
	Layout;

	using
	channels
	=
	typename
	Layout::channels;

	static constexpr mizuiro::size_type const element_count
		=
		metal::size<
			channels
		>::value;
};

}
}
}

#endif
