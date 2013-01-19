//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_OPERATORS_SCALAR_MULTIPLY_HPP_INCLUDED
#define MIZUIRO_COLOR_OPERATORS_SCALAR_MULTIPLY_HPP_INCLUDED

#include <mizuiro/color/for_each_channel.hpp>
#include <mizuiro/color/is_color.hpp>
#include <mizuiro/color/object_impl.hpp>
#include <mizuiro/color/operators/detail/scalar_multiply.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace color
{

template<
	typename Color,
	typename Scalar
>
typename boost::enable_if<
	color::is_color<
		Color
	>,
	color::object<
		typename Color::format
	>
>::type
operator*(
	Color const &_color,
	Scalar const _scalar
)
{
	typedef color::object<
		typename Color::format
	> result_type;

	result_type result(
		_color
	);

	color::for_each_channel(
		_color,
		color::operators::detail::scalar_multiply<
			result_type,
			Scalar
		>(
			result,
			_scalar
		)
	);

	return result;
}

template<
	typename Color,
	typename Scalar
>
typename boost::enable_if<
	color::is_color<
		Color
	>,
	color::object<
		typename Color::format
	>
>::type
operator*(
	Scalar const _scalar,
	Color const &_color
)
{
	return _color * _scalar;
}

}
}

#endif
