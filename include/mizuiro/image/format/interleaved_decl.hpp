//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_INTERLEAVED_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_INTERLEAVED_DECL_HPP_INCLUDED

#include <mizuiro/color/format/argument.hpp>
#include <mizuiro/color/format/base_decl.hpp>
#include <mizuiro/image/format/interleaved_fwd.hpp>


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
class interleaved final
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

	format_store_type
	format_store() const;
};

}
}
}

#endif
