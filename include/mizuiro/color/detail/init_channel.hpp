//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_DETAIL_INIT_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_INIT_CHANNEL_HPP_INCLUDED

namespace mizuiro
{
namespace color
{
namespace detail
{

template<
	typename Value,
	typename Channel
>
class init_channel {
public:
	typedef Value value_type;
	typedef Channel channel;

	explicit init_channel(
		Value const &value_
	)
	:
		value_(value_)
	{}
	
	Value const &
	value() const
	{
		return value_;
	}
private:
	Value const value_;
};

}
}
}

#endif
