//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_INTERLEAVED_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_INTERLEAVED_DECL_HPP_INCLUDED

#include <mizuiro/color/format_argument.hpp>
#include <mizuiro/color/format_base_decl.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/image/interleaved_fwd.hpp>
#include <mizuiro/image/pitch_type.hpp>


namespace mizuiro
{
namespace image
{

MIZUIRO_DETAIL_IGNORE_EFFCPP

template<
	typename DimType,
	typename ColorFormat
>
class interleaved
:
	private
		mizuiro::color::format_base<
			ColorFormat
		>::type

{
	typedef typename mizuiro::color::format_base<
		ColorFormat
	>::type format_base;
public:
	typedef ColorFormat color_format;

	typedef typename format_base::format_store_type format_store_type;

	typedef DimType dim;

	typedef typename mizuiro::image::pitch_type<
		dim
	>::type pitch;

	explicit interleaved(
		format_store_type const & =
			mizuiro::color::format_argument<
				color_format
			>::get()
	);

	format_store_type const
	format_store() const;
};

MIZUIRO_DETAIL_POP_WARNING

}
}

#endif
