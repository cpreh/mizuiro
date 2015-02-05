//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_ARRAY_INIT_HPP_INCLUDED
#define MIZUIRO_DETAIL_ARRAY_INIT_HPP_INCLUDED

#include <mizuiro/array.hpp>
#include <mizuiro/size_type.hpp>
#include <mizuiro/detail/array_init_each_rt.hpp>
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
inline
mizuiro::array<
	typename
	std::result_of<
		Function()
	>::type,
	Size
>
array_init(
	Function const &_function
)
{
	return
		mizuiro::detail::array_init_each_rt<
			Size
		>(
			[
				&_function
			](
				mizuiro::size_type
			)
			{
				return
					_function();
			}
		);
}

}
}

#endif
