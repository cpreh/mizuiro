//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_INIT_DETAIL_CHANNEL_VALUE_HPP_INCLUDED
#define MIZUIRO_COLOR_INIT_DETAIL_CHANNEL_VALUE_HPP_INCLUDED

#include <mizuiro/color/init/detail/channel_value_fwd.hpp>


namespace mizuiro
{
namespace color
{
namespace init
{
namespace detail
{

template<
	typename Value,
	typename Channel
>
class channel_value
{
public:
	using
	value_type
	=
	Value;

	using
	channel_type
	=
	Channel;

	channel_value(
		Value const &_value,
		Channel const &_channel
	)
	:
		value_(
			_value
		),
		channel_(
			_channel
		)
	{
	}

	[[nodiscard]]
	Value const &
	value() const
	{
		return
			value_;
	}

	[[nodiscard]]
	Channel const &
	channel() const
	{
		return
			channel_;
	}
private:
	Value value_;

	Channel channel_;
};

}
}
}
}

#endif
