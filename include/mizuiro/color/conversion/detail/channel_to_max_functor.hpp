//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERSION_DETAIL_CHANNEL_TO_MAX_FUNCTOR_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERSION_DETAIL_CHANNEL_TO_MAX_FUNCTOR_HPP_INCLUDED

#include <mizuiro/color/conversion/detail/channel_to_max.hpp>
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
class channel_to_max_functor
{
	MIZUIRO_DETAIL_NONASSIGNABLE(
		channel_to_max_functor
	);
public:
	typedef void result_type;

	explicit
	channel_to_max_functor(
		Dest &_dest
	)
	:
		dest_(
			_dest
		)
	{
	}

	template<
		typename Channel
	>
	result_type
	operator()(
		Channel const &_channel
	) const
	{
		conversion::detail::channel_to_max(
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
