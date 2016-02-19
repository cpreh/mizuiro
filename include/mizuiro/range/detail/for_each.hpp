//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_RANGE_DETAIL_FOR_EACH_HPP_INCLUDED
#define MIZUIRO_RANGE_DETAIL_FOR_EACH_HPP_INCLUDED

#include <mizuiro/detail/external_begin.hpp>
#include <type_traits>
#include <mizuiro/detail/external_end.hpp>


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
	Range::empty::value
>::type
for_each(
	Range const &,
	Function const &
)
{
}

template<
	typename Range,
	typename Function
>
inline
typename
std::enable_if<
	!Range::empty::value
>::type
for_each(
	Range const &_range,
	Function const &_function
)
{
	_function(
		_range
	);

	mizuiro::range::detail::for_each(
		_range.next(),
		_function
	);
}

}
}
}

#endif
