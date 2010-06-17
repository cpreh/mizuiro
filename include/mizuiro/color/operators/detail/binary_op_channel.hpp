#ifndef MIZUIRO_COLOR_OPERATORS_DETAIL_BINARY_OP_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_OPERATORS_DETAIL_BINARY_OP_CHANNEL_HPP_INCLUDED

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
	template<
		typename
	> class Operation,
	typename Color1,
	typename Color2
>
class binary_op_channel
{
public:
	explicit binary_op_channel(
		Color1 &color1_,
		Color2 const &color2_
	)
	:
		color1_(color1_),
		color2_(color2_)
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
		typedef typename color::types::channel_value<
			typename Color1::format,
			Channel
		>::type channel_value_;

		color1_. template set<
			Channel
		>(
			static_cast<
				channel_value_
			>(
				Operation<
					channel_value_
				>()
				(
					color1_. template get<
						Channel
					>(),
					color2_. template get<
						Channel
					>()
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
