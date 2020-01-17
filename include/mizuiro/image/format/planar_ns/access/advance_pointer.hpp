//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_PLANAR_NS_ACCESS_ADVANCE_POINTER_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_PLANAR_NS_ACCESS_ADVANCE_POINTER_HPP_INCLUDED

#include <mizuiro/difference_type.hpp>
#include <mizuiro/size_type.hpp>
#include <mizuiro/image/access/advance_pointer.hpp>
#include <mizuiro/image/access/advance_pointer_ns/tag.hpp>
#include <mizuiro/image/format/store_fwd.hpp>
#include <mizuiro/image/format/planar_ns/tag.hpp>
#include <mizuiro/image/types/pointer.hpp>
#include <fcppt/container/array/init.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <fcppt/config/external_end.hpp>


namespace mizuiro
{
namespace image
{
namespace access
{
namespace advance_pointer_ns
{

template<
	typename Access,
	typename Format,
	typename Constness
>
mizuiro::image::types::pointer<
	Access,
	Format,
	Constness
>
advance_pointer_adl(
	mizuiro::image::access::advance_pointer_ns::tag,
	mizuiro::image::format::planar_ns::tag<
		Format
	>,
	Access,
	Constness,
	mizuiro::image::format::store<
		Format
	> const &,
	mizuiro::image::types::pointer<
		Access,
		Format,
		Constness
	> const _data,
	mizuiro::difference_type const _diff
)
{
	return
		fcppt::container::array::init<
			std::array<
				typename
				mizuiro::image::types::pointer<
					Access,
					Format,
					Constness
				>::value_type,
				Format::element_count
			>
		>(
			[
				&_data,
				_diff
			](
				mizuiro::size_type const _index
			)
			{
				return
					_data[
						_index
					]
					+
					_diff;
			}
		);
}

}
}
}
}

#endif
