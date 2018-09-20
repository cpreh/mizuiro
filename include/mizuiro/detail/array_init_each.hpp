//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_ARRAY_INIT_EACH_HPP_INCLUDED
#define MIZUIRO_DETAIL_ARRAY_INIT_EACH_HPP_INCLUDED

#include <mizuiro/array.hpp>
#include <mizuiro/size_type.hpp>
#include <mizuiro/detail/array_init_each_impl.hpp>
#include <mizuiro/mpl/integral_size.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


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
			mizuiro::mpl::integral_size<
				0
			>
		)
	>::type,
	Size
>
array_init_each(
	Function const &_function
)
{
	return
		mizuiro::detail::array_init_each_impl<
			Size,
			0
		>(
			_function
		);
}

}
}

#endif
