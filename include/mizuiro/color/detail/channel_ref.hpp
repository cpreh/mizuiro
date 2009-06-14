#ifndef MIZUIRO_COLOR_DETAIL_CHANNEL_REF_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_CHANNEL_REF_HPP_INCLUDED

namespace mizuiro
{
namespace color
{
namespace detail
{

template<
	typename Layout,
	typename Channel,
	typename Constness
>
struct channel_ref {
	typedef typename Layout:: template channel_reference<
		Channel,
		Constness
	>::type type;
};

}
}
}

#endif
