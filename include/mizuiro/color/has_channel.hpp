//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_HAS_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_HAS_CHANNEL_HPP_INCLUDED

#include <mizuiro/detail/external_begin.hpp>
#include <boost/mpl/contains.hpp>
#include <mizuiro/detail/external_end.hpp>

namespace mizuiro
{
namespace color
{
template
<
	typename Format,
	typename Channel
>
struct has_channel
:
boost::mpl::contains<
	typename Format::layout::order,
	Channel
>
{
};
}
}

#endif
