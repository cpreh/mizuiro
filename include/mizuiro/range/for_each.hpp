//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_RANGE_FOR_EACH_HPP_INCLUDED
#define MIZUIRO_RANGE_FOR_EACH_HPP_INCLUDED

#include <mizuiro/range/make.hpp>
#include <mizuiro/range/detail/for_each.hpp>


namespace mizuiro
{
namespace range
{

template<
	typename Sequence,
	typename Function
>
inline
void
for_each(
	Sequence const &_sequence,
	Function const &_function
)
{
	mizuiro::range::detail::for_each(
		mizuiro::range::make(
			_sequence
		),
		_function
	);
}

}
}

#endif
