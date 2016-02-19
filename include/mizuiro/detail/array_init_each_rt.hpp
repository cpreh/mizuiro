//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_ARRAY_INIT_EACH_RT_HPP_INCLUDED
#define MIZUIRO_DETAIL_ARRAY_INIT_EACH_RT_HPP_INCLUDED

#include <mizuiro/array.hpp>
#include <mizuiro/decltype.hpp>
#include <mizuiro/size_type.hpp>
#include <mizuiro/detail/array_init_each.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <type_traits>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace detail
{

template<
	mizuiro::size_type Size,
	typename Function
>
mizuiro::array<
	typename
	std::result_of<
		Function(
			mizuiro::size_type
		)
	>::type,
	Size
>
array_init_each_rt(
	Function const &_function
)
{
	return
		mizuiro::detail::array_init_each<
			Size
		>(
			[
				&_function
			](
				auto const _index
			)
			{
				return
					_function(
						MIZUIRO_DECLTYPE(
							_index
						)::value
					);
			}
		);
}

}
}

#endif
