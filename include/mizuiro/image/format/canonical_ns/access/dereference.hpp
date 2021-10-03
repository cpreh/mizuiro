//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_CANONICAL_NS_ACCESS_DEREFERENCE_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_CANONICAL_NS_ACCESS_DEREFERENCE_HPP_INCLUDED

#include <mizuiro/access/normal.hpp>
#include <mizuiro/image/access/dereference_ns/tag.hpp>
#include <mizuiro/image/format/store_fwd.hpp>
#include <mizuiro/image/format/canonical_ns/tag.hpp>
#include <mizuiro/image/format/canonical_ns/types/pointer.hpp>
#include <mizuiro/image/format/canonical_ns/types/reference.hpp>
#include <mizuiro/image/types/pointer.hpp>
#include <mizuiro/image/types/reference.hpp>


namespace mizuiro::image::access::dereference_ns
{

template<
	typename ImageFormat,
	typename Constness
>
mizuiro::image::types::reference<
	mizuiro::access::normal,
	ImageFormat,
	Constness
>
dereference_adl(
	mizuiro::image::access::dereference_ns::tag,
	mizuiro::access::normal,
	mizuiro::image::format::canonical_ns::tag<
		ImageFormat
	>,
	Constness,
	mizuiro::image::format::store<
		ImageFormat
	> const &,
	mizuiro::image::types::pointer<
		mizuiro::access::normal,
		ImageFormat,
		Constness
	> const _data
)
{
	return
		*_data;
}

}

#endif
