//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_LAYOUT_DETAIL_HAS_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_LAYOUT_DETAIL_HAS_CHANNEL_HPP_INCLUDED

#include <fcppt/mpl/list/contains.hpp>


namespace mizuiro::color::layout::detail
{

template<
	typename Order,
	typename Channel
>
using
has_channel
=
fcppt::mpl::list::contains<
	Order,
	Channel
>;

}

#endif
