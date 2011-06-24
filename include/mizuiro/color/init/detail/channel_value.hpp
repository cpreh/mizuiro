//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_INIT_DETAIL_CHANNEL_VALUE_HPP_INCLUDED
#define MIZUIRO_COLOR_INIT_DETAIL_CHANNEL_VALUE_HPP_INCLUDED

#include <mizuiro/color/init/detail/channel_value_fwd.hpp>
#include <mizuiro/detail/nonassignable.hpp>

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
	MIZUIRO_DETAIL_NONASSIGNABLE(
		channel_value
	);
public:
	typedef Value value_type;

	typedef Channel channel_type;

	channel_value(
		Value const &_value,
		Channel const &_channel
	)
	:
		value_(_value),
		channel_(_channel)
	{}
	
	Value const &
	value() const
	{
		return value_;
	}

	Channel const &
	channel() const
	{
		return channel_;
	}
private:
	Value const value_;

	Channel const channel_;
};

}
}
}
}

#endif
