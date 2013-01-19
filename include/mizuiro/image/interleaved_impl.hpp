//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_INTERLEAVED_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_INTERLEAVED_IMPL_HPP_INCLUDED

#include <mizuiro/color/format_base_impl.hpp>
#include <mizuiro/image/interleaved_decl.hpp>


template<
	typename DimType,
	typename ColorFormat
>
mizuiro::image::interleaved<
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
typename mizuiro::image::interleaved<
	DimType,
	ColorFormat
>::format_store_type const
mizuiro::image::interleaved<
	DimType,
	ColorFormat
>::format_store() const
{
	return
		this->format_store_base();
}

#endif
