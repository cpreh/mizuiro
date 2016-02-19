//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_RANGE_FOR_EACH_RANGE_HPP_INCLUDED
#define MIZUIRO_RANGE_FOR_EACH_RANGE_HPP_INCLUDED

#include <mizuiro/range/detail/for_each.hpp>


namespace mizuiro
{
namespace range
{

template<
	typename Range,
	typename Function
>
inline
void
for_each_range(
	Range const &_range,
	Function const &_function
)
{
	mizuiro::range::detail::for_each(
		_range,
		_function
	);
}

}
}

#endif
