#ifndef MIZUIRO_COLOR_FOR_SOME_CHANNELS_HPP_INCLUDED
#define MIZUIRO_COLOR_FOR_SOME_CHANNELS_HPP_INCLUDED

#include <boost/mpl/for_each.hpp>
#include <boost/mpl/filter_view.hpp>

namespace mizuiro
{
namespace color
{

template<
	typename Color,
	typename Filter,
	typename Function
>
void
for_some_channels(
	Function const &fun
)
{
	boost::mpl::for_each<
		boost::mpl::filter_view<
			typename Color::layout::layout::order
			Filter
		>
	>(
		fun
	);
}

}
}

#endif
