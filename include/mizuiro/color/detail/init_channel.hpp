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
