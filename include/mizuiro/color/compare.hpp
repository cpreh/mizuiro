//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_COMPARE_HPP_INCLUDED
#define MIZUIRO_COLOR_COMPARE_HPP_INCLUDED

#include <mizuiro/color/decay_channel_proxy.hpp>
#include <mizuiro/color/get_channel.hpp>
#include <mizuiro/color/is_color.hpp>
#include <mizuiro/color/access/channels.hpp>
#include <mizuiro/color/format/compatible.hpp>
#include <mizuiro/color/format/get.hpp>
#include <fcppt/algorithm/all_of.hpp>
#include <fcppt/algorithm/loop_break_metal.hpp>


// TODO: Where do we put this? ^


namespace mizuiro
{
namespace color
{

template<
	typename Color1,
	typename Color2,
	typename CompareChannel
>
bool
compare(
	Color1 const &_color1,
	Color2 const &_color2,
	CompareChannel const &_compare
)
{
	static_assert(
		mizuiro::color::format::compatible<
			mizuiro::color::format::get<
				Color1
			>,
			mizuiro::color::format::get<
				Color2
			>
		>::value,
		"Color formats must be compatible to be comparable"
	);

	static_assert(
		mizuiro::color::is_color<
			Color1
		>::value,
		"Color1 must be a color type"
	);

	static_assert(
		mizuiro::color::is_color<
			Color2
		>::value,
		"Color2 must be a color type"
	);

	return
		fcppt::algorithm::all_of(
			mizuiro::color::access::channels<
				typename
				Color1::format
			>(
				_color1.format_store()
			),
			[
				&_color1,
				&_color2,
				&_compare
			](
				auto const _channel
			)
			-> bool
			{
				return
					_compare(
						mizuiro::color::decay_channel_proxy(
							_color1.get(
								mizuiro::color::get_channel(
									_channel
								)
							)
						),
						mizuiro::color::decay_channel_proxy(
							_color2.get(
								mizuiro::color::get_channel(
									_channel
								)
							)
						)
					);
			}
		);
}

}
}

#endif
