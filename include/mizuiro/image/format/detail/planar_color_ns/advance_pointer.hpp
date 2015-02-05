//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_DETAIL_PLANAR_COLOR_NS_ADVANCE_POINTER_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_DETAIL_PLANAR_COLOR_NS_ADVANCE_POINTER_HPP_INCLUDED

#include <mizuiro/difference_type.hpp>
#include <mizuiro/size_type.hpp>
#include <mizuiro/color/access/advance_pointer.hpp>
#include <mizuiro/color/access/advance_pointer_ns/tag.hpp>
#include <mizuiro/color/format/store_fwd.hpp>
#include <mizuiro/color/types/pointer.hpp>
#include <mizuiro/detail/array_init_each_rt.hpp>
#include <mizuiro/image/format/detail/planar_color_ns/pointer.hpp>
#include <mizuiro/image/format/detail/planar_color_ns/tag.hpp>


namespace mizuiro
{
namespace color
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
mizuiro::color::types::pointer<
	Access,
	Format,
	Constness
>
advance_pointer_adl(
	mizuiro::color::access::advance_pointer_ns::tag,
	mizuiro::image::format::detail::planar_color_ns::tag<
		Format
	>,
	Access,
	Constness,
	mizuiro::color::format::store<
		Format
	> const &,
	mizuiro::color::types::pointer<
		Access,
		Format,
		Constness
	> const _data,
	mizuiro::difference_type const _diff
)
{
	return
		mizuiro::detail::array_init_each_rt<
			Format::element_count
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
