//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ACCESS_DATA_HPP_INCLUDED
#define MIZUIRO_IMAGE_ACCESS_DATA_HPP_INCLUDED

#include <mizuiro/image/access/data_ns/tag.hpp>
#include <mizuiro/image/format/make_tag_of.hpp>
#include <mizuiro/image/format/store_fwd.hpp>
#include <mizuiro/image/types/pointer.hpp>
#include <mizuiro/image/types/reference.hpp>


namespace mizuiro
{
namespace image
{
namespace access
{

template<
	typename Access,
	typename Constness,
	typename ImageFormat
>
mizuiro::image::types::pointer<
	Access,
	ImageFormat,
	Constness
>
data(
	mizuiro::image::format::store<
		ImageFormat
	> const &_format,
	mizuiro::image::types::reference<
		Access,
		ImageFormat,
		Constness
	> const &_ref
)
{
	return
		data_adl(
			mizuiro::image::access::data_ns::tag(),
			Access(),
			mizuiro::image::format::make_tag_of<
				ImageFormat
			>(),
			Constness(),
			_format,
			_ref
		);
}

}
}
}

#endif
