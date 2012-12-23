//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_HOMOGENOUS_DYNAMIC_DECL_HPP_INCLUDED
#define MIZUIRO_COLOR_HOMOGENOUS_DYNAMIC_DECL_HPP_INCLUDED

#include <mizuiro/array.hpp>
#include <mizuiro/size_type.hpp>
#include <mizuiro/color/homogenous_dynamic_fwd.hpp>
#include <mizuiro/detail/nonassignable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <fcppt/config/external_end.hpp>


namespace mizuiro
{
namespace color
{

template<
	typename ChannelType,
	typename AvailableChannels,
	AvailableChannels AllChannels,
	mizuiro::size_type Size
>
struct homogenous_dynamic
{
	MIZUIRO_DETAIL_NONASSIGNABLE(
		homogenous_dynamic
	);
public:
	typedef AvailableChannels available_channels;

	typedef typename mizuiro::array<
		AvailableChannels,
		Size
	>::type channel_array;

	typedef typename mizuiro::array<
		mizuiro::size_type,
		static_cast<
			std::size_t
		>(
			AllChannels
		)
	>::type channel_index_array;

	explicit
	homogenous_dynamic(
		channel_array const &
	);

	typedef ChannelType channel_type;

	static mizuiro::size_type const element_count = Size;

	typedef channel_array layout;

	channel_array const order;

	channel_index_array const indices;
};

}
}

#endif
