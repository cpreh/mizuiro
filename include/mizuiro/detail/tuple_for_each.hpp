//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_TUPLE_FOR_EACH_HPP_INCLUDED
#define MIZUIRO_DETAIL_TUPLE_FOR_EACH_HPP_INCLUDED

#include <mizuiro/detail/external_begin.hpp>
#include <cstddef>
#include <tuple>
#include <type_traits>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace detail
{

template<
	typename Function,
	std::size_t Index = 0,
	typename... Params
>
inline
typename
std::enable_if<
	Index
	==
	sizeof...(
		Params
	)
>::type
tuple_for_each(
	Function const &,
	std::tuple<
		Params...
	> const &
)
{
}

template<
	typename Function,
	std::size_t Index = 0,
	typename... Params
>
inline
typename
std::enable_if<
	Index
	<
	sizeof...(
		Params
	)
>::type
tuple_for_each(
	Function const &_function,
	std::tuple<
		Params...
	> const &_values
)
{
	_function(
		std::get<
			Index
		>(
			_values
		)
	);

	mizuiro::detail::tuple_for_each<
		Function,
		Index + 1
	>(
		_function,
		_values
	);
}


}
}

#endif
