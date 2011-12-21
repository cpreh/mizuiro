//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_IS_LUMINANCE_HPP_INCLUDED
#define MIZUIRO_COLOR_IS_LUMINANCE_HPP_INCLUDED

#include <mizuiro/color/channel/luminance.hpp>
#include <mizuiro/color/types/has_channel_static.hpp>


namespace mizuiro
{
namespace color
{

template<
	typename Format
>
struct is_luminance
:
color::types::has_channel_static<
	Format,
	channel::luminance
>
{
};

}
}

#endif
