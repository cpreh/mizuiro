//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_MAKE_COMPARE_FUNCTION_HPP_INCLUDED
#define MIZUIRO_COLOR_MAKE_COMPARE_FUNCTION_HPP_INCLUDED

#include <mizuiro/color/compare_function.hpp>


namespace mizuiro
{
namespace color
{

template<
	typename CompareChannel
>
mizuiro::color::compare_function<
	CompareChannel
>
make_compare_function(
	CompareChannel const &_compare_channel
)
{
	return
		mizuiro::color::compare_function<
			CompareChannel
		>(
			_compare_channel
		);
}

}
}

#endif
