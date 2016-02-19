//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_MAKE_COMPARE_FUNCTION_HPP_INCLUDED
#define MIZUIRO_COLOR_MAKE_COMPARE_FUNCTION_HPP_INCLUDED

#include <mizuiro/color/compare.hpp>


namespace mizuiro
{
namespace color
{

template<
	typename CompareChannel
>
decltype(
	auto
)
make_compare_function(
	CompareChannel const &_compare_channel
)
{
	return
		[
			_compare_channel
		](
			auto const &_color1,
			auto const &_color2
		)
		{
			return
				mizuiro::color::compare(
					_color1,
					_color2,
					_compare_channel
				);
		};
}

}
}

#endif
