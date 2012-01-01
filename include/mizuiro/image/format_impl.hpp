//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_IMPL_HPP_INCLUDED

#include <mizuiro/color/format_base_impl.hpp>
#include <mizuiro/image/format_decl.hpp>


template<
	typename DimType,
	typename ImageFormat
>
mizuiro::image::format<
	DimType,
	ImageFormat
>::format(
	color_format_store_type const &_color_format
)
:
	color_format_base(
		_color_format
	)
{
}

template<
	typename DimType,
	typename ImageFormat
>
typename mizuiro::image::format<
	DimType,
	ImageFormat
>::color_format_store_type const
mizuiro::image::format<
	DimType,
	ImageFormat
>::color_format_store() const
{
	return this->format_store_base();
}

#endif
