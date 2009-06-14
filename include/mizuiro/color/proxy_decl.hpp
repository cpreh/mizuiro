#ifndef MIZUIRO_COLOR_PROXY_DECL_HPP_INCLUDED
#define MIZUIRO_COLOR_PROXY_DECL_HPP_INCLUDED

#include <mizuiro/color/proxy_fwd.hpp>
#include <mizuiro/color/detail/channel_ref.hpp>

namespace mizuiro
{
namespace color
{

template<
	typename Layout
>
class proxy {
public:
	typedef Layout layout;
	typedef typename layout::pointer pointer;

	explicit proxy(
		pointer data
	);

	template<
		typename Channel
	>
	void
	set(
		typename detail::channel_ref<
			layout,
			Channel,
			mizuiro::detail::const_tag
		>::type 
	);

	/*
	template<
		typename Channel
	>
	typename detail::channel_ref<
		channels,
		Channel
	>::type
	get() const;
	*/
private:
	pointer data_;	
};

}
}

#endif
