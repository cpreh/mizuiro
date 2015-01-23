//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_DETAIL_PREPARE_STORE_UNITS_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_PREPARE_STORE_UNITS_HPP_INCLUDED

#include <mizuiro/nonconst_tag.hpp>
#include <mizuiro/image/access/data.hpp>
#include <mizuiro/image/access/stride.hpp>
#include <mizuiro/image/format/store_fwd.hpp>
#include <mizuiro/image/types/needs_prepare.hpp>
#include <mizuiro/image/types/pointer.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <memory>
#include <type_traits>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace image
{
namespace detail
{

template<
	typename Access,
	typename ImageFormat,
	typename Dest
>
typename
std::enable_if<
	mizuiro::image::types::needs_prepare<
		ImageFormat
	>::value,
	void
>::type
inline
prepare_store_units(
	mizuiro::image::format::store<
		ImageFormat
	> const &_format,
	Dest const &_dest
)
{
	std::uninitialized_fill_n(
		mizuiro::image::access::data<
			Access,
			mizuiro::nonconst_tag
		>(
			_format,
			_dest
		),
		mizuiro::image::access::stride<
			Access
		>(
			_format
		),
		typename
		std::remove_pointer<
			mizuiro::image::types::pointer<
				Access,
				ImageFormat,
				mizuiro::nonconst_tag
			>
		>::type{}
	);
}

template<
	typename Access,
	typename ImageFormat,
	typename Dest
>
typename
std::enable_if<
	!mizuiro::image::types::needs_prepare<
		ImageFormat
	>::value,
	void
>::type
inline
prepare_store_units(
	mizuiro::image::format::store<
		ImageFormat
	> const &,
	Dest const &
)
{
}

}
}
}

#endif
