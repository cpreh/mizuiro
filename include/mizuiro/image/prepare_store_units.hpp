//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_PREPARE_STORE_UNITS_HPP_INCLUDED
#define MIZUIRO_IMAGE_PREPARE_STORE_UNITS_HPP_INCLUDED

#include <mizuiro/access/is.hpp>
#include <mizuiro/image/detail/prepare_store_units.hpp>
#include <mizuiro/image/format/store_fwd.hpp>


namespace mizuiro
{
namespace image
{

template<
	typename Access,
	typename ImageFormat,
	typename Dest
>
inline
void
prepare_store_units(
	mizuiro::image::format::store<
		ImageFormat
	> const &_format,
	Dest &_dest
)
{
	static_assert(
		mizuiro::access::is<
			Access
		>::value,
		"Invalid Access type"
	);

	mizuiro::image::detail::prepare_store_units<
		Access
	>(
		_format,
		_dest
	);
}

}
}

#endif
