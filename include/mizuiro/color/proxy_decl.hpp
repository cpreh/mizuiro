#ifndef MIZUIRO_COLOR_PROXY_DECL_HPP_INCLUDED
#define MIZUIRO_COLOR_PROXY_DECL_HPP_INCLUDED

#include <mizuiro/color/proxy_fwd.hpp>
#include <mizuiro/const_tag.hpp>

namespace mizuiro
{
namespace color
{

template<
	typename Format,
	typename Constness
>
class proxy {
public:
	typedef Format format;

	typedef typename Format:: template pointer<
		Constness
	>::type pointer;

	explicit proxy(
		pointer data
	);

	template<
		typename Other
	>
	proxy const &
	operator=(
		Other const &
	) const;

	template<
		typename Channel
	>
	void
	set(
		typename format::template channel_value_type<
			Channel
		>::type const &
	) const;

	template<
		typename Channel
	>
	typename format:: template channel_reference<
		Channel,
		mizuiro::const_tag
	>::type
	get() const;

	pointer
	data() const;
private:
	pointer data_;	
};

}
}

#endif
