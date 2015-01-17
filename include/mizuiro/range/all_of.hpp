//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_RANGE_ALL_OF_HPP_INCLUDED
#define MIZUIRO_RANGE_ALL_OF_HPP_INCLUDED

#include <mizuiro/range/make.hpp>
#include <mizuiro/range/detail/all_of.hpp>


namespace mizuiro
{
namespace range
{

template<
	typename Sequence,
	typename Function
>
inline
bool
all_of(
	Sequence const &_sequence,
	Function const &_function
)
{
	return
		mizuiro::range::detail::all_of(
			mizuiro::range::make(
				_sequence
			),
			_function
		);
}

}
}

#endif
