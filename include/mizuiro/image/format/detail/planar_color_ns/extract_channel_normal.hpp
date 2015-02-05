//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_DETAIL_PLANAR_COLOR_NS_EXTRACT_CHANNEL_NORMAL_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_DETAIL_PLANAR_COLOR_NS_EXTRACT_CHANNEL_NORMAL_HPP_INCLUDED

#include <mizuiro/access/normal.hpp>
#include <mizuiro/color/access/channel_index.hpp>
#include <mizuiro/color/access/extract_channel_ns/tag.hpp>
#include <mizuiro/color/format/store_fwd.hpp>
#include <mizuiro/color/types/channel_reference.hpp>
#include <mizuiro/color/types/pointer.hpp>
#include <mizuiro/image/format/detail/planar_color_ns/tag.hpp>


namespace mizuiro
{
namespace color
{
namespace access
{
namespace extract_channel_ns
{

template<
	typename Format,
	typename Channel,
	typename Constness
>
mizuiro::color::types::channel_reference<
	mizuiro::access::normal,
	Format,
	Channel,
	Constness
>
extract_channel_adl(
	mizuiro::color::access::extract_channel_ns::tag,
	mizuiro::access::normal,
	mizuiro::image::format::detail::planar_color_ns::tag<
		Format
	>,
	mizuiro::color::format::store<
		Format
	> const &_format,
	Channel const &_channel,
	Constness const &,
	mizuiro::color::types::pointer<
		mizuiro::access::normal,
		Format,
		Constness
	> const _data
)
{
	return
		*_data[
			mizuiro::color::access::channel_index(
				_format,
				_channel
			)
		];
}

}
}
}
}

#endif
