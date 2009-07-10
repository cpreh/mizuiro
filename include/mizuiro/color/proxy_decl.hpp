#ifndef MIZUIRO_COLOR_PROXY_DECL_HPP_INCLUDED
#define MIZUIRO_COLOR_PROXY_DECL_HPP_INCLUDED

#include <mizuiro/color/proxy_fwd.hpp>

namespace mizuiro
{
namespace color
{

template<
	typename Layout,
	typename Constness
>
class proxy {
public:
	typedef Layout layout;

	typedef typename Layout:: template pointer<
		Constness
	>::type pointer;

	explicit proxy(
		pointer data
	);

	template<
		typename Channel
	>
	void
	set(
		typename layout::template channel_reference<
			Channel,
			mizuiro::detail::const_tag
		>::type 
	);

	template<
		typename Channel
	>
	typename layout:: template channel_reference<
		Channel,
		mizuiro::detail::const_tag
	>::type
	get() const;
private:
	pointer data_;	
};

}
}

#endif
