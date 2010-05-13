#ifndef MIZUIRO_COLOR_OUTPUT_HPP_INCLUDED
#define MIZUIRO_COLOR_OUTPUT_HPP_INCLUDED

#include <mizuiro/color/detail/output_channel.hpp>
#include <mizuiro/color/for_each_channel.hpp>
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

	mizuiro::color::for_each_channel<
		typename Color::format
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
