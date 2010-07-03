//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_OPERATORS_SCALAR_MULTIPLY_HPP_INCLUDED
#define MIZUIRO_COLOR_OPERATORS_SCALAR_MULTIPLY_HPP_INCLUDED

#include <mizuiro/color/operators/detail/scalar_multiply.hpp>
#include <mizuiro/color/is_color.hpp>
#include <mizuiro/color/object_impl.hpp>
#include <mizuiro/color/for_each_channel.hpp>
#include <boost/utility/enable_if.hpp>

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
	Color const &color_,
	Scalar const scalar_
)
{
	typedef typename Color::format format;

	typedef color::object<
		format
	> result_type;

	result_type result(
		color_
	);

	color::for_each_channel<
		format
	>(
		color::operators::detail::scalar_multiply<
			Color,
			Scalar
		>(
			result,
			scalar_
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
	Scalar const scalar_,
	Color const &color_
)
{
	return color_ * scalar_;
}

}
}

#endif
