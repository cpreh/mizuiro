//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FOR_SOME_CHANNELS_HPP_INCLUDED
#define MIZUIRO_COLOR_FOR_SOME_CHANNELS_HPP_INCLUDED

#include <boost/mpl/for_each.hpp>
#include <boost/mpl/filter_view.hpp>

namespace mizuiro
{
namespace color
{

template<
	typename Format,
	typename Filter,
	typename Function
>
void
for_some_channels(
	Function const &_function
)
{
	boost::mpl::for_each<
		boost::mpl::filter_view<
			typename Format::order,
			Filter
		>
	>(
		_function
	);
}

}
}

#endif
