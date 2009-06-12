#ifndef MIZUIRO_COLOR_PROXY_HPP_INCLUDED
#define MIZUIRO_COLOR_PROXY_HPP_INCLUDED

namespace mizurio
{
namespace color
{

template<
	typename Color
>
class proxy {
public:
	proxy(
		raw_pointer
	);

	value_type operator() const;

	template<
		typename Channel
	>
	void
	set(
		typename boost::mpl::find<
			typename Color::channels,
			Channel
		>::ref_type
	);

	template<
		typename Channel
	>
	typename boost::mpl::find<
		typename Color::channels,
		Channel
	>::ref_type
	get() const;
private:
	
};

}
}

#endif
