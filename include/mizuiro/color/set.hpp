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
