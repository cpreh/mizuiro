//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_CANONICAL_NS_ACCESS_MAKE_STORE_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_CANONICAL_NS_ACCESS_MAKE_STORE_HPP_INCLUDED

#include <mizuiro/image/access/make_store_ns/tag.hpp>
#include <mizuiro/image/format/store_fwd.hpp>
#include <mizuiro/image/format/canonical_ns/tag.hpp>
#include <mizuiro/image/types/store.hpp>


namespace mizuiro::image::access::make_store_ns
{

template<
	typename Access,
	typename ImageFormat
>
mizuiro::image::types::store<
	Access,
	ImageFormat
>
make_store_adl(
	mizuiro::image::access::make_store_ns::tag,
	mizuiro::image::format::canonical_ns::tag<
		ImageFormat
	>,
	Access,
	mizuiro::image::format::store<
		ImageFormat
	> const &,
	typename ImageFormat::dim const &_dim
)
{
	return
		mizuiro::image::types::store<
			Access,
			ImageFormat
		>(
			_dim.content()
		);
}

}

#endif
