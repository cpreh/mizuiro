//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_OPERATORS_DETAIL_BINARY_OP_HPP_INCLUDED
#define MIZUIRO_COLOR_OPERATORS_DETAIL_BINARY_OP_HPP_INCLUDED

#include <mizuiro/color/for_each_channel.hpp>
#include <mizuiro/color/is_color.hpp>
#include <mizuiro/color/object_impl.hpp>
#include <mizuiro/color/operators/detail/binary_op_channel.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <type_traits>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace operators
{
namespace detail
{

template<
	template<
		typename
	> class Operation,
	typename Color1,
	typename Color2
>
mizuiro::color::object<
	typename Color1::format
>
binary_op(
	Color1 const &_color1,
	Color2 const &_color2
)
{
	static_assert(
		std::is_same<
			typename Color1::format,
			typename Color2::format
		>::value,
		"Color1 and Color2 must use the same color format"
	);

	static_assert(
		mizuiro::color::is_color<
			Color1
		>::value,
		"Color1 must be a color type"
	);

	static_assert(
		mizuiro::color::is_color<
			Color2
		>::value,
		"Color2 must be a color type"
	);

	typedef
	mizuiro::color::object<
		typename Color1::format
	>
	result_type;

	result_type result(
		_color1
	);

	mizuiro::color::for_each_channel(
		_color1,
		mizuiro::color::operators::detail::binary_op_channel<
			Operation,
			result_type,
			Color2
		>(
			result,
			_color2
		)
	);

	return
		result;
}

}
}
}
}

#endif
