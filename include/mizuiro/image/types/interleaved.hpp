//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_TYPES_INTERLEAVED_HPP_INCLUDED
#define MIZUIRO_IMAGE_TYPES_INTERLEAVED_HPP_INCLUDED

#include <mizuiro/color/object_fwd.hpp>
#include <mizuiro/color/types/pointer.hpp>
#include <mizuiro/image/is_interleaved.hpp>
#include <mizuiro/image/types/pointer.hpp>
#include <mizuiro/image/types/value_type.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>


namespace mizuiro
{
namespace image
{
namespace types
{

MIZUIRO_DETAIL_IGNORE_EFFCPP

template<
	typename Access,
	typename ImageFormat,
	typename Constness
>
struct pointer<
	Access,
	ImageFormat,
	Constness,
	typename boost::enable_if<
		mizuiro::image::is_interleaved<
			ImageFormat
		>
	>::type
>
:
mizuiro::color::types::pointer<
	Access,
	typename ImageFormat::color_format,
	Constness
>
{
};

MIZUIRO_DETAIL_POP_WARNING

template<
	typename ImageFormat
>
struct value_type<
	ImageFormat,
	typename boost::enable_if<
		mizuiro::image::is_interleaved<
			ImageFormat
		>
	>::type
>
{
	typedef ::mizuiro::color::object<
		typename ImageFormat::color_format
	> type;
};

}
}
}

#endif
