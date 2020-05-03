//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_PLANAR_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_PLANAR_DECL_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <mizuiro/color/format/argument.hpp>
#include <mizuiro/color/format/base_decl.hpp>
#include <mizuiro/image/format/planar_fwd.hpp>
#include <mizuiro/image/format/detail/planar_color.hpp>


namespace mizuiro
{
namespace image
{
namespace format
{

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
	using
	format_base
	=
	mizuiro::color::format::base<
		mizuiro::image::format::detail::planar_color<
			ColorFormat
		>
	>;
public:
	using
	color_format
	=
	mizuiro::image::format::detail::planar_color<
		ColorFormat
	>;

	using
	format_store_type
	=
	typename
	format_base::format_store_type;

	using
	dim
	=
	DimType;

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

	[[nodiscard]]
	format_store_type
	format_store() const;
};

}
}
}

#endif
