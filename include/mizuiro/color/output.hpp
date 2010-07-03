//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


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
