//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_IS_STATIC_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_IS_STATIC_HPP_INCLUDED

#include <mizuiro/color/format_is_static.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/image/interleaved_fwd.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/type_traits/integral_constant.hpp>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace image
{

template<
	typename Format
>
struct format_is_static
:
boost::false_type
{
};

MIZUIRO_DETAIL_IGNORE_EFFCPP

template<
	typename DimType,
	typename ColorFormat
>
struct format_is_static<
	mizuiro::image::interleaved<
		DimType,
		ColorFormat
	>
>
:
mizuiro::color::format_is_static<
	ColorFormat
>
{
};

MIZUIRO_DETAIL_POP_WARNING

}
}

#endif
