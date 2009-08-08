#ifndef MIZUIRO_COLOR_FOR_EACH_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_FOR_EACH_CHANNEL_HPP_INCLUDED

#include <boost/mpl/for_each.hpp>

namespace mizuiro
{
namespace color
{

template<
	typename Format,
	typename Function
>
void
for_each_channel(
	Function const &fun
)
{
	boost::mpl::for_each<
		typename Format::layout::order
	>(
		fun
	);
}

}
}

#endif
