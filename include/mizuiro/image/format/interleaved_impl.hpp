//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_INTERLEAVED_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_INTERLEAVED_IMPL_HPP_INCLUDED

#include <mizuiro/color/format/base_impl.hpp>
#include <mizuiro/image/format/interleaved_decl.hpp>


template<
	typename DimType,
	typename ColorFormat
>
mizuiro::image::format::interleaved<
	DimType,
	ColorFormat
>::interleaved(
	format_store_type const &_format
)
:
	format_base(
		_format
	)
{
}

template<
	typename DimType,
	typename ColorFormat
>
mizuiro::image::format::interleaved<
	DimType,
	ColorFormat
>::interleaved(
	interleaved const &
) noexcept
= default;

template<
	typename DimType,
	typename ColorFormat
>
typename
mizuiro::image::format::interleaved<
	DimType,
	ColorFormat
>::format_store_type
mizuiro::image::format::interleaved<
	DimType,
	ColorFormat
>::format_store() const
{
	return
		this->format_store_base();
}

#endif
