//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_OPERATORS_SCALAR_MULTIPLY_HPP_INCLUDED
#define MIZUIRO_COLOR_OPERATORS_SCALAR_MULTIPLY_HPP_INCLUDED

#include <mizuiro/color/for_each_channel.hpp>
#include <mizuiro/color/is_color.hpp>
#include <mizuiro/color/object_impl.hpp>
#include <mizuiro/color/operators/detail/scalar_multiply.hpp>


namespace mizuiro
{
namespace color
{

template<
	typename Color,
	typename Scalar
>
mizuiro::color::object<
	typename Color::format
>
operator*(
	Color const &_color,
	Scalar const _scalar
)
{
	static_assert(
		mizuiro::color::is_color<
			Color
		>::value,
		"Color must be a color type"
	);

	typedef mizuiro::color::object<
		typename Color::format
	> result_type;

	result_type result(
		_color
	);

	mizuiro::color::for_each_channel(
		_color,
		mizuiro::color::operators::detail::scalar_multiply<
			result_type,
			Scalar
		>(
			result,
			_scalar
		)
	);

	return
		result;
}

template<
	typename Color,
	typename Scalar
>
mizuiro::color::object<
	typename Color::format
>
operator*(
	Scalar const _scalar,
	Color const &_color
)
{
	static_assert(
		mizuiro::color::is_color<
			Color
		>::value,
		"Color must be a color type"
	);

	return
		_color * _scalar;
}

}
}

#endif
