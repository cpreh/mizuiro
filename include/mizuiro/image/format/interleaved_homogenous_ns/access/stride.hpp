//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_INTERLEAVED_HOMOGENOUS_NS_ACCESS_STRIDE_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_INTERLEAVED_HOMOGENOUS_NS_ACCESS_STRIDE_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <mizuiro/access/stride.hpp>
#include <mizuiro/image/access/stride_ns/tag.hpp>
#include <mizuiro/image/format/store_fwd.hpp>
#include <mizuiro/image/format/interleaved_homogenous_ns/tag.hpp>
#include <mizuiro/image/types/store_unit.hpp>
#include <mizuiro/mpl/integral_size.hpp>


namespace mizuiro
{
namespace image
{
namespace access
{
namespace stride_ns
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
	mizuiro::image::format::interleaved_homogenous_ns::tag<
		Format
	>,
	mizuiro::image::format::store<
		Format
	> const &
)
{
	return
		// TODO: Can we combine this implementation with heterogenous?
		mizuiro::access::stride<
			mizuiro::mpl::integral_size<
				Format::color_format::element_count
			>,
			mizuiro::mpl::integral_size<
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
}
}
}

#endif
