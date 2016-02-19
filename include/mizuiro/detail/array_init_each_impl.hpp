//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_ARRAY_INIT_EACH_IMPL_HPP_INCLUDED
#define MIZUIRO_DETAIL_ARRAY_INIT_EACH_IMPL_HPP_INCLUDED

#include <mizuiro/array.hpp>
#include <mizuiro/size_type.hpp>
#include <mizuiro/detail/array_init_each_impl.hpp>
#include <mizuiro/mpl/integral_size.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <type_traits>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace detail
{

template<
	mizuiro::size_type Size,
	mizuiro::size_type Index,
	typename Function,
	typename... Args
>
typename
std::enable_if<
	Index
	==
	Size,
	mizuiro::array<
		typename
		std::result_of<
			Function(
				mizuiro::mpl::integral_size<
					0
				>
			)
		>::type,
		Size
	>
>::type
array_init_each_impl(
	Function const &,
	Args const & ..._args
)
{
	return
		mizuiro::array<
			typename
			std::result_of<
				Function(
					mizuiro::mpl::integral_size<
						0
					>
				)
			>::type,
			Size
		>{{
			_args...
		}};
}

template<
	mizuiro::size_type Size,
	mizuiro::size_type Index,
	typename Function,
	typename... Args
>
typename
std::enable_if<
	Index
	<
	Size,
	mizuiro::array<
		typename
		std::result_of<
			Function(
				mizuiro::mpl::integral_size<
					0
				>
			)
		>::type,
		Size
	>
>::type
array_init_each_impl(
	Function const &_function,
	Args const & ..._args
)
{
	return
		mizuiro::detail::array_init_each_impl<
			Size,
			Index + 1u
		>(
			_function,
			_args...,
			_function(
				mizuiro::mpl::integral_size<
					Index
				>{}
			)
		);
}

}
}

#endif
