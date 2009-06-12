#ifndef MIZUIRO_COLOR_FORMAT_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_HPP_INCLUDED

namespace mizuiro
{
namespace color
{

template<
	typename Channel,
	typename Layout
>
struct format {
	typedef Channel channel;
	typedef Layout layout;
};

}
}

#endif
