#ifndef MIZUIRO_COLOR_OPERATORS_SCALAR_MULTIPLY_HPP_INCLUDED
#define MIZUIRO_COLOR_OPERATORS_SCALAR_MULTIPLY_HPP_INCLUDED

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
	typename Color::format format;

	typedef color::object<
		format
	> result_type;

	result_type result(
		color_
	);

	color::for_each_channel<
		format
	>(
		detail::scalar_multiply<
			Color,
			Scalar
		>(
			result,
			scalar_
		)
	);

	return result;
}

}
}

#endif
