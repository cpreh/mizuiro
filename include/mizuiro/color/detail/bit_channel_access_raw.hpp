//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_DETAIL_BIT_CHANNEL_ACCESS_RAW_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_BIT_CHANNEL_ACCESS_RAW_HPP_INCLUDED

#include <mizuiro/const_raw_pointer.hpp>
#include <mizuiro/raw_pointer.hpp>
#include <mizuiro/color/detail/bit_channel_access_normal.hpp>
#include <mizuiro/color/types/channel_value.hpp>
#include <mizuiro/detail/copy_n.hpp>
#include <mizuiro/detail/uint_least.hpp>


namespace mizuiro
{
namespace color
{
namespace detail
{

template<
	typename Format,
	typename Channel
>
class bit_channel_access_raw
{
private:
	typedef mizuiro::color::detail::bit_channel_access_normal<
		Format,
		Channel
	> access_normal;

	typedef typename mizuiro::color::types::channel_value<
		Format,
		Channel
	>::type value_type;

	typedef typename mizuiro::detail::uint_least<
		total_bits
	>::type color_uint;
public:
	static
	value_type
	read(
		mizuiro::const_raw_pointer const _data
	)
	{
		color_uint temp;

		mizuiro::detail::copy_n(
			_data,
			sizeof(color_uint),
			reinterpret_cast<
				mizuiro::raw_pointer
			>(
				&temp
			)
		);

		return
			access_normal::read(
				&temp
			);
	}

	static
	void
	write(
		mizuiro::raw_pointer const _data,
		value_type const _value
	)
	{
		color_uint temp;

		mizuiro::detail::copy_n(
			_data,
			sizeof(color_uint),
			reinterpret_cast<
				mizuiro::raw_pointer
			>(
				&temp
			)
		);

		access_normal::write(
			&temp,
			_value
		);

		mizuiro::detail::copy_n(
			reinterpret_cast<
				mizuiro::const_raw_pointer
			>(
				&temp
			),
			sizeof(color_uint),
			_data
		);
	}
};

}
}
}

#endif
