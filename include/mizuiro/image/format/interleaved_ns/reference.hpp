//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_INTERLEAVED_NS_REFERENCE_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_INTERLEAVED_NS_REFERENCE_HPP_INCLUDED

#include <mizuiro/color/proxy_impl.hpp>
#include <mizuiro/image/format/interleaved_ns/tag.hpp>
#include <mizuiro/image/types/reference_ns/tag.hpp>


namespace mizuiro
{
namespace image
{
namespace types
{
namespace reference_ns
{

template<
	typename Access,
	typename ImageFormat,
	typename Constness
>
mizuiro::color::proxy<
	Access,
	typename
	ImageFormat::color_format,
	Constness
>
reference_adl(
	mizuiro::image::types::reference_ns::tag,
	Access,
	mizuiro::image::format::interleaved_ns::tag<
		ImageFormat
	>,
	Constness
);

}
}
}
}

#endif
