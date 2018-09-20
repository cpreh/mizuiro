//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CHANNEL_IS_HPP_INCLUDED
#define MIZUIRO_COLOR_CHANNEL_IS_HPP_INCLUDED

#include <mizuiro/color/channel/tag_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace channel
{

template<
	typename T
>
using is
=
std::is_base_of<
	mizuiro::color::channel::tag<
		T
	>,
	T
>;

}
}
}

#endif
