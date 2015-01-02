//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_HAS_CHANNEL_STATIC_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_HAS_CHANNEL_STATIC_HPP_INCLUDED

#include <mizuiro/color/types/static_channels.hpp>
#include <mizuiro/mpl/bool.hpp>
#include <mizuiro/mpl/contains.hpp>


namespace mizuiro
{
namespace color
{
namespace format
{

template<
	typename Format,
	typename Channel
>
using
has_channel_static
=
mizuiro::mpl::bool_<
	mizuiro::mpl::contains<
		mizuiro::color::types::static_channels<
			Format
		>,
		Channel
	>()
>;

}
}
}

#endif
