//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_SET_HPP_INCLUDED
#define MIZUIRO_COLOR_SET_HPP_INCLUDED

namespace mizuiro
{
namespace color
{

template<
	typename Channel,
	typename Color
>
void
set(
	Color &col,
	typename Color::layout:: template channel_value_type<
		Channel
	>::type const &v
)
{
	col. template set<
		Channel
	>(
		v
	);
}

}
}

#endif
