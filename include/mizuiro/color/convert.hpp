//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERT_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERT_HPP_INCLUDED

#include <mizuiro/color/is_color.hpp>
#include <mizuiro/color/object_impl.hpp>
#include <mizuiro/color/format/argument.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>


namespace mizuiro
{
namespace color
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4686)

template<
	typename Converter,
	typename DestFormat,
	typename Src
>
mizuiro::color::object<
	DestFormat
>
convert(
	Src const &_src,
	typename
	mizuiro::color::object<
		DestFormat
	>::format_store_type const &_dest_format =
		mizuiro::color::format::argument<
			DestFormat
		>::get()
)
{
	static_assert(
		mizuiro::color::is_color<
			Src
		>::value,
		"Src must be a color type"
	);

	return
		Converter:: template execute<
			DestFormat
		>(
			_src,
			_dest_format
		);
}

FCPPT_PP_POP_WARNING

}
}

#endif
