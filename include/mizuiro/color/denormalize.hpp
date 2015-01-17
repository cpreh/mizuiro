//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_DENORMALIZE_HPP_INCLUDED
#define MIZUIRO_COLOR_DENORMALIZE_HPP_INCLUDED

#include <mizuiro/color/access/channel_max.hpp>
#include <mizuiro/color/access/channel_min.hpp>
#include <mizuiro/color/format/store_fwd.hpp>
#include <mizuiro/color/types/channel_value.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <type_traits>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace color
{

template<
	typename Format,
	typename Channel,
	typename Float
>
mizuiro::color::types::channel_value<
	Format,
	Channel
>
denormalize(
	mizuiro::color::format::store<
		Format
	> const &_format_store,
	Channel const &_channel,
	Float const _src
)
{
	static_assert(
		std::is_floating_point<
			Float
		>::value,
		"Float must be a floating point type"
	);

	return
		static_cast<
			mizuiro::color::types::channel_value<
				Format,
				Channel
			>
		>(
			static_cast<
				Float
			>(
				mizuiro::color::access::channel_min(
					_format_store,
					_channel
				)
			)
			+
			_src
			*
			(
				static_cast<
					Float
				>(
					mizuiro::color::access::channel_max(
						_format_store,
						_channel
					)
				)
				-
				static_cast<
					Float
				>(
					mizuiro::color::access::channel_min(
						_format_store,
						_channel
					)
				)
			)
		);
}

}
}

#endif
