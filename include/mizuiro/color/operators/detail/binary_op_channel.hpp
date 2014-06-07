//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_OPERATORS_DETAIL_BINARY_OP_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_OPERATORS_DETAIL_BINARY_OP_CHANNEL_HPP_INCLUDED

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
	template<
		typename
	> class Operation,
	typename Color1,
	typename Color2
>
class binary_op_channel
{
	MIZUIRO_DETAIL_NONASSIGNABLE(
		binary_op_channel
	);
public:
	binary_op_channel(
		Color1 &_color1,
		Color2 const &_color2
	)
	:
		color1_(
			_color1
		),
		color2_(
			_color2
		)
	{
	}

	typedef
	void
	result_type;

	template<
		typename Channel
	>
	result_type
	operator()(
		Channel const &_channel
	) const
	{
		typedef
		mizuiro::color::types::channel_value<
			typename Color1::format,
			Channel
		>
		channel_value;

		color1_.set(
			_channel,
			static_cast<
				channel_value
			>(
				Operation<
					channel_value
				>()
				(
					color1_.get(
						_channel
					),
					color2_.get(
						_channel
					)
				)
			)
		);
	}
private:
	Color1 &color1_;

	Color2 const &color2_;
};

}
}
}
}

#endif
