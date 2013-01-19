//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CHANNEL_IS_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_CHANNEL_IS_CHANNEL_HPP_INCLUDED

#include <mizuiro/color/channel/tag.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/type_traits/is_base_of.hpp>
#include <mizuiro/detail/external_end.hpp>

namespace mizuiro
{
namespace color
{
namespace channel
{

MIZUIRO_DETAIL_IGNORE_EFFCPP

template<
	typename T
>
struct is_channel
:
boost::is_base_of<
	channel::tag,
	T
>
{
};

MIZUIRO_DETAIL_POP_WARNING

}
}
}

#endif
