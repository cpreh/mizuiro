//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_LAYOUT_DETAIL_HAS_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_LAYOUT_DETAIL_HAS_CHANNEL_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <metal/list/contains.hpp>
#include <fcppt/config/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace layout
{
namespace detail
{

template<
	typename Order,
	typename Channel
>
using
has_channel
=
metal::contains<
	Order,
	Channel
>;

}
}
}
}

#endif
