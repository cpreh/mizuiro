//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_OUTPUT_HPP_INCLUDED
#define MIZUIRO_COLOR_OUTPUT_HPP_INCLUDED

#include <mizuiro/decltype.hpp>
#include <mizuiro/color/for_each_channel_range.hpp>
#include <mizuiro/color/is_color.hpp>
#include <mizuiro/color/format/get.hpp>
#include <mizuiro/color/types/channel_value.hpp>
#include <mizuiro/detail/promote_type.hpp>
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
		[
			&_color,
			&_stream
		](
			auto const &_range_inner
		)
		{
			_stream <<
				static_cast<
					mizuiro::detail::promote_type<
						mizuiro::color::types::channel_value<
							mizuiro::color::format::get<
								Color
							>,
							MIZUIRO_DECLTYPE(
								_range_inner.get()
							)
						>
					>
				>(
					_color.get(
						_range_inner.get()
					)
				);

			if(
				!MIZUIRO_DECLTYPE(
					_range_inner.next()
				)::empty::value
			)
				_stream <<
					_stream.widen(',');
		}
	);

	_stream
		<< _stream.widen(')');

	return
		_stream;
}

}
}

#endif
