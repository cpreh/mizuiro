//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_RANGE_DETAIL_ALL_OF_HPP_INCLUDED
#define MIZUIRO_RANGE_DETAIL_ALL_OF_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace mizuiro
{
namespace range
{
namespace detail
{

template<
	typename Range,
	typename Function
>
inline
typename
std::enable_if<
	Range::empty::value,
	bool
>::type
all_of(
	Range const &,
	Function const &
)
{
	return
		true;
}

template<
	typename Range,
	typename Function
>
inline
typename
std::enable_if<
	!Range::empty::value,
	bool
>::type
all_of(
	Range const &_range,
	Function const &_function
)
{
	return
		_function(
			_range.get()
		)
		&&
		mizuiro::range::detail::all_of(
			_range.next(),
			_function
		);
}

}
}
}

#endif
