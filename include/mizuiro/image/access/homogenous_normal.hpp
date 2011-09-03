//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ACCESS_HOMOGENOUS_NORMAL_HPP_INCLUDED
#define MIZUIRO_IMAGE_ACCESS_HOMOGENOUS_NORMAL_HPP_INCLUDED

#include <mizuiro/image/access/color_stride.hpp>
#include <mizuiro/image/access/data_store_size.hpp>
#include <mizuiro/image/format_store_fwd.hpp>
#include <mizuiro/color/is_homogenous.hpp>
#include <mizuiro/access/normal.hpp>
#include <mizuiro/size_type.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <mizuiro/detail/external_end.hpp>

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
	mizuiro::access::normal,
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
		mizuiro::access::normal const &,
		image::format_store<ImageFormat> const &
	)
	{
		return ImageFormat::color_format::element_count;
	}
};

template<
	typename ImageFormat
>
struct data_store_size<
	mizuiro::access::normal,
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
		mizuiro::access::normal const &_access,
		image::format_store<ImageFormat> const &_format,
		Dim const &_dim
	)
	{
		return
			_dim.content()
			*
			access::color_stride<
				mizuiro::access::normal,
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
