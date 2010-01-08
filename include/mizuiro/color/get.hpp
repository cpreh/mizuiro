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
typename Color::layout:: template channel_reference<
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
