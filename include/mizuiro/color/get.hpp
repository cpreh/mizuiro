//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_GET_HPP_INCLUDED
#define MIZUIRO_COLOR_GET_HPP_INCLUDED

#include <mizuiro/const_tag.hpp>

namespace mizuiro
{
namespace color
{

template<
	typename Channel,
	typename Color
>
typename 
color::types::channel_reference
<
	typename Color::access,
	typename Color::format,
	Channel,
	mizuiro::const_tag
>::type
get(
	Color const &c
)
{
	return c. template get<
		Channel	
	>();
}

}
}

#endif
