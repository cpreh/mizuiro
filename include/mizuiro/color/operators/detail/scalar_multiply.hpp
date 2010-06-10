#ifndef MIZUIRO_COLOR_OPERATORS_DETAIL_SCALAR_MULTIPLY_HPP_INCLUDED
#define MIZUIRO_COLOR_OPERATORS_DETAIL_SCALAR_MULTIPLY_HPP_INCLUDED

#include <mizuiro/color/types/channel_value.hpp>

namespace mizuiro
{
namespace color
{
namespace operators
{
namespace detail
{

template<
	typename Color,
	typename Scalar
>
class scalar_multiply
{
public:
	explicit scalar_multiply(
		Color &color_,
		Scalar const scalar_
	)
	:
		color_(color_),
		scalar_(scalar_)
	{}

	typedef void result_type;

	template<
		typename Channel
	>
	result_type
	operator()(
		Channel const &
	) const
	{
		color_. template set<
			Channel
		>(
			static_cast<
				typename color::types::channel_value<
					typename Color::format,
					Channel
				>::type
			>(
				static_cast<
					Scalar
				>(
					color_. template get<
						Channel
					>()
				)
				*
				scalar_
			)
		);
	}
private:
	Color &color_;
	Scalar const scalar_;
};

}
}
}
}

#endif
