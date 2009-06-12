#ifndef MIZUIRO_COLOR_PROXY_HPP_INCLUDED
#define MIZUIRO_COLOR_PROXY_HPP_INCLUDED

#include <mizuiro/color/proxy_fwd.hpp>

namespace mizurio
{
namespace color
{

template<
	typename Channels
>
class proxy {
public:
	explicit proxy(
		pointer data_
	);

	template<
		typename Channel
	>
	void
	set(
		typename boost::mpl::find<
			Channels,
			Channel
		>::ref_type
	);

	template<
		typename Channel
	>
	typename boost::mpl::find<
		Channels,
		Channel
	>::ref_type
	get() const;
private:
	pointer data_;	
};

}
}

#endif
