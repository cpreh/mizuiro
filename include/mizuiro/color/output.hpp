//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_OUTPUT_HPP_INCLUDED
#define MIZUIRO_COLOR_OUTPUT_HPP_INCLUDED

#include <mizuiro/color/for_each_channel_range.hpp>
#include <mizuiro/color/is_color.hpp>
#include <mizuiro/color/detail/output_channel.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <ostream>
#include <type_traits>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace color
{

template<
	typename Ch,
	typename Traits,
	typename Color
>
typename
std::enable_if<
	mizuiro::color::is_color<
		Color
	>::value,
	std::basic_ostream<
		Ch,
		Traits
	> &
>::type
operator<<(
	std::basic_ostream<
		Ch,
		Traits
	> &_stream,
	Color const &_color
)
{
	_stream
		<< _stream.widen('(');

	mizuiro::color::for_each_channel_range(
		_color,
		mizuiro::color::detail::output_channel<
			Ch,
			Traits,
			Color
		>(
			_stream,
			_color
		)
	);

	_stream
		<< _stream.widen(')');

	return
		_stream;
}

}
}

#endif
