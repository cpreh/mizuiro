//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_INTERLEAVED_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_INTERLEAVED_DECL_HPP_INCLUDED

#include <mizuiro/color/format/argument.hpp>
#include <mizuiro/color/format/base_decl.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/image/pitch_type.hpp>
#include <mizuiro/image/format/interleaved_fwd.hpp>


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
class interleaved
:
	private
		mizuiro::color::format::base<
			ColorFormat
		>
{
	typedef
	mizuiro::color::format::base<
		ColorFormat
	>
	format_base;
public:
	typedef
	ColorFormat
	color_format;

	typedef
	typename
	format_base::format_store_type
	format_store_type;

	typedef
	DimType
	dim;

	typedef
	typename
	mizuiro::image::pitch_type<
		dim
	>::type
	pitch;

	explicit
	interleaved(
		format_store_type const & =
			mizuiro::color::format::argument<
				color_format
			>::get()
	);

	interleaved(
		interleaved const &
	) noexcept;

	format_store_type const
	format_store() const;
};

MIZUIRO_DETAIL_POP_WARNING

}
}
}

#endif
