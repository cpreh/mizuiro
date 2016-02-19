//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_RANGE_FOR_EACH_HPP_INCLUDED
#define MIZUIRO_RANGE_FOR_EACH_HPP_INCLUDED

#include <mizuiro/range/for_each_range.hpp>
#include <mizuiro/range/detail/range_get.hpp>


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
for_each(
	Range const &_range,
	Function const &_function
)
{
	mizuiro::range::for_each_range(
		_range,
		mizuiro::range::detail::range_get<
			Function
		>(
			_function
		)
	);
}

}
}

#endif
