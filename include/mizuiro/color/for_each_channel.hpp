//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


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
