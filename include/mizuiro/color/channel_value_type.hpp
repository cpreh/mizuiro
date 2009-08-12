#ifndef MIZUIRO_COLOR_CHANNEL_VALUE_TYPE_HPP_INCLUDED
#define MIZUIRO_COLOR_CHANNEL_VALUE_TYPE_HPP_INCLUDED

namespace mizuiro
{
namespace color
{

template<
	typename Format,
	typename Channel
>
struct channel_value_type {
	typedef typename Format:: template channel_value_type<
		Channel
	>::type type;
};

}
}

#endif
