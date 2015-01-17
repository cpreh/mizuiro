//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_COMPARE_FUNCTION_HPP_INCLUDED
#define MIZUIRO_COLOR_COMPARE_FUNCTION_HPP_INCLUDED

#include <mizuiro/color/compare.hpp>
#include <mizuiro/detail/nonassignable.hpp>


namespace mizuiro
{
namespace color
{

template<
	typename CompareChannel
>
class compare_function
{
	MIZUIRO_DETAIL_NONASSIGNABLE(
		compare_function
	);
public:
	explicit
	compare_function(
		CompareChannel const &_compare_channel
	)
	:
		compare_channel_(
			_compare_channel
		)
	{
	}

	typedef
	bool
	result_type;

	template<
		typename Color1,
		typename Color2
	>
	result_type
	operator()(
		Color1 const &_color1,
		Color2 const &_color2
	) const
	{
		return
			mizuiro::color::compare(
				_color1,
				_color2,
				compare_channel_
			);
	}
private:
	CompareChannel const compare_channel_;
};

}
}

#endif
