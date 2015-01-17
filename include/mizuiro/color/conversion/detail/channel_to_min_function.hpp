//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERSION_DETAIL_CHANNEL_TO_MIN_FUNCTION_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERSION_DETAIL_CHANNEL_TO_MIN_FUNCTION_HPP_INCLUDED

#include <mizuiro/color/conversion/detail/channel_to_min.hpp>
#include <mizuiro/detail/nonassignable.hpp>


namespace mizuiro
{
namespace color
{
namespace conversion
{
namespace detail
{

template<
	typename Dest
>
class channel_to_min_function
{
	MIZUIRO_DETAIL_NONASSIGNABLE(
		channel_to_min_function
	);
public:
	explicit
	channel_to_min_function(
		Dest &_dest
	)
	:
		dest_(
			_dest
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
		mizuiro::color::conversion::detail::channel_to_min(
			dest_,
			_channel
		);
	}
private:
	Dest &dest_;
};

}
}
}
}

#endif
