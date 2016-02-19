//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_PLANAR_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_PLANAR_DECL_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <mizuiro/color/format/argument.hpp>
#include <mizuiro/color/format/base_decl.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/image/format/planar_fwd.hpp>
#include <mizuiro/image/format/detail/planar_color.hpp>


namespace mizuiro
{
namespace image
{
namespace format
{

MIZUIRO_DETAIL_IGNORE_EFFCPP

template<
	typename DimType,
	typename ColorFormat
>
class planar final
:
	private
		mizuiro::color::format::base<
			mizuiro::image::format::detail::planar_color<
				ColorFormat
			>
		>
{
	typedef
	mizuiro::color::format::base<
		mizuiro::image::format::detail::planar_color<
			ColorFormat
		>
	>
	format_base;
public:
	typedef
	mizuiro::image::format::detail::planar_color<
		ColorFormat
	>
	color_format;

	typedef
	typename
	format_base::format_store_type
	format_store_type;

	typedef
	DimType
	dim;

	static
	mizuiro::size_type const element_count =
		ColorFormat::element_count;

	explicit
	planar(
		format_store_type const & =
			mizuiro::color::format::argument<
				color_format
			>::get()
	);

	planar(
		planar const &
	) noexcept;

	format_store_type
	format_store() const;
};

MIZUIRO_DETAIL_POP_WARNING

}
}
}

#endif
