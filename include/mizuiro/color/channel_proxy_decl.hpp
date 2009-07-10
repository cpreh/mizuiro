#ifndef MIZUIRO_COLOR_CHANNEL_PROXY_DECL_HPP_INCLUDED
#define MIZUIRO_COLOR_CHANNEL_PROXY_DECL_HPP_INCLUDED

namespace mizuiro
{
namespace color
{

template<
	typename Layout,
	typename Channel,
	typename Constness
>
class channel_proxy {
public:
	typedef Layout layout;
	typedef Channel channel;

	typedef typename layout:: template channel_value_type<
		Channel
	>::type value_type;

	typedef typename layout:: template pointer<
		Constness
	>::type pointer;

	channel_proxy(
		pointer data
	);

	channel_proxy &
	operator=(
		value_type
	);

	operator value_type() const;
private:
	pointer data_;	
};

}
}

#endif
