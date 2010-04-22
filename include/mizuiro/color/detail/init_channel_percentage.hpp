#ifndef MIZUIRO_COLOR_DETAIL_INIT_CHANNEL_PERCENTAGE_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_INIT_CHANNEL_PERCENTAGE_HPP_INCLUDED

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
class init_channel_percentage
{
public:
	typedef Value value_type;
	typedef Channel channel;

	explicit init_channel_percentage(
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
