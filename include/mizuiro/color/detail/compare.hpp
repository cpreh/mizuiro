//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_DETAIL_COMPARE_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_COMPARE_HPP_INCLUDED

#include <mizuiro/color/decay_channel_proxy.hpp>
#include <mizuiro/color/is_color.hpp>
#include <mizuiro/detail/nonassignable.hpp>


namespace mizuiro
{
namespace color
{
namespace detail
{

template<
	typename Color1,
	typename Color2,
	typename CompareChannel
>
class compare
{
	MIZUIRO_DETAIL_NONASSIGNABLE(
		compare
	);
public:
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

	compare(
		Color1 const &_color1,
		Color2 const &_color2,
		CompareChannel const &_compare_channel
	)
	:
		color1_(
			_color1
		),
		color2_(
			_color2
		),
		compare_channel_(
			_compare_channel
		)
	{
	}

	template<
		typename Channel
	>
	bool
	operator()(
		Channel const &_channel
	) const
	{
		return
			compare_channel_(
				mizuiro::color::decay_channel_proxy(
					color1_.get(
						_channel
					)
				),
				mizuiro::color::decay_channel_proxy(
					color2_.get(
						_channel
					)
				)
			);
	}
private:
	Color1 const &color1_;

	Color2 const &color2_;

	CompareChannel const compare_channel_;
};

}
}
}

#endif
