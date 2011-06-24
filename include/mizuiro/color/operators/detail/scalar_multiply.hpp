//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_OPERATORS_DETAIL_SCALAR_MULTIPLY_HPP_INCLUDED
#define MIZUIRO_COLOR_OPERATORS_DETAIL_SCALAR_MULTIPLY_HPP_INCLUDED

#include <mizuiro/color/types/channel_value.hpp>
#include <mizuiro/detail/nonassignable.hpp>

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
	MIZUIRO_DETAIL_NONASSIGNABLE(
		scalar_multiply
	);
public:
	explicit scalar_multiply(
		Color &_color,
		Scalar const _scalar
	)
	:
		color_(_color),
		scalar_(_scalar)
	{}

	typedef void result_type;

	template<
		typename Channel
	>
	result_type
	operator()(
		Channel const &_channel
	) const
	{
		color_.set(
			_channel,
			static_cast<
				typename color::types::channel_value<
					typename Color::format,
					Channel
				>::type
			>(
				static_cast<
					Scalar
				>(
					color_.get(
						_channel
					)
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
