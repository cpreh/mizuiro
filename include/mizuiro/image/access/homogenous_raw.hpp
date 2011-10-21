//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ACCESS_HOMOGENOUS_RAW_HPP_INCLUDED
#define MIZUIRO_IMAGE_ACCESS_HOMOGENOUS_RAW_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <mizuiro/access/raw.hpp>
#include <mizuiro/color/is_homogenous.hpp>
#include <mizuiro/image/format_store_fwd.hpp>
#include <mizuiro/image/access/color_stride.hpp>
#include <mizuiro/image/access/data_store_size.hpp>


namespace mizuiro
{
namespace image
{
namespace access
{

template<
	typename ImageFormat
>
struct color_stride<
	mizuiro::access::raw,
	ImageFormat,
	typename boost::enable_if<
		mizuiro::color::is_homogenous<
			typename ImageFormat::color_format
		>
	>::type
>
{
	static
	mizuiro::size_type
	execute(
		mizuiro::access::raw const &,
		image::format_store<ImageFormat> const &
	)
	{
		return
			ImageFormat::color_format::element_count
			* sizeof(typename ImageFormat::color_format::channel_type);
	}
};


template<
	typename ImageFormat
>
struct data_store_size<
	mizuiro::access::raw,
	ImageFormat,
	typename boost::enable_if<
		mizuiro::color::is_homogenous<
			typename ImageFormat::color_format
		>
	>::type
>
{
	template<
		typename Dim
	>
	static
	mizuiro::size_type
	execute(
		mizuiro::access::raw const &_access,
		image::format_store<ImageFormat> const &_format,
		Dim const &_dim
	)
	{
		return
			_dim.content()
			*
			access::color_stride<
				mizuiro::access::raw,
				ImageFormat
			>::execute(
				_access,
				_format
			);
	}
};

}
}
}

#endif
