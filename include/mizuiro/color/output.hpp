#ifndef MIZUIRO_COLOR_OUTPUT_HPP_INCLUDED
#define MIZUIRO_COLOR_OUTPUT_HPP_INCLUDED

#include <mizuiro/color/detail/output_channel.hpp>
#include <boost/mpl/for_each.hpp>
#include <ostream>

namespace mizuiro
{
namespace color
{

template<
	typename Ch,
	typename Traits,
	typename Color
>
std::basic_ostream<
	Ch,
	Traits
> &
operator<<(
	std::basic_ostream<
		Ch,
		Traits
	> &s,
	Color const &c
)
{
	s << s.widen('(');

	boost::mpl::for_each<
		typename Color::format::layout::order
	>(
		detail::output_channel<
			Ch,
			Traits,
			Color
		>(
			s,
			c
		)
	);

	s << s.widen(')');
		
	return s;	
}

}
}

#endif
