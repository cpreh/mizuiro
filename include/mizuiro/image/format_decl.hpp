//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_DECL_HPP_INCLUDED

#include <mizuiro/image/format_fwd.hpp>
#include <mizuiro/image/detail/pitch_type.hpp>
#include <mizuiro/color/format_argument.hpp>
#include <mizuiro/color/format_base_decl.hpp>

namespace mizuiro
{
namespace image
{

template<
	typename DimType,
	typename ImageFormat
>
class format
:
	private color::format_base<
		typename ImageFormat::color_format
	>::type
{
	typedef typename color::format_base<
		typename ImageFormat::color_format
	>::type color_format_base;
public:
	typedef typename color_format_base::format_store_type color_format_store_type;

	typedef DimType dim;

	typedef ImageFormat image_format;

	typedef typename detail::pitch_type<
		dim
	>::type pitch_type;

	typedef typename image_format::color_format color_format;

	explicit format(
		color_format_store_type const & =
			color::format_argument<color_format>::get()
	);

	color_format_store_type const
	color_format_store() const;
};

}
}

#endif
