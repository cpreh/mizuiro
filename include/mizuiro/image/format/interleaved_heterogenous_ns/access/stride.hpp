//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_INTERLEAVED_HETEROGENOUS_NS_ACCESS_STRIDE_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_INTERLEAVED_HETEROGENOUS_NS_ACCESS_STRIDE_HPP_INCLUDED

#include <mizuiro/integral_size.hpp>
#include <mizuiro/size_type.hpp>
#include <mizuiro/access/stride.hpp>
#include <mizuiro/image/access/stride_ns/tag.hpp>
#include <mizuiro/image/format/store_fwd.hpp>
#include <mizuiro/image/format/interleaved_heterogenous_ns/tag.hpp>
#include <mizuiro/image/types/store_unit.hpp>


namespace mizuiro::image::access::stride_ns
{

template<
	typename Access,
	typename Format
>
inline
mizuiro::size_type
stride_adl(
	mizuiro::image::access::stride_ns::tag,
	Access const _access,
	mizuiro::image::format::interleaved_heterogenous_ns::tag<
		Format
	>,
	mizuiro::image::format::store<
		Format
	> const &
)
{
	return
		mizuiro::access::stride<
			mizuiro::integral_size<
				1U
			>,
			mizuiro::integral_size<
				sizeof(
					mizuiro::image::types::store_unit<
						Format
					>
				)
			>
		>(
			_access
		);
}

}

#endif
