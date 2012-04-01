//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_IS_STATIC_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_IS_STATIC_HPP_INCLUDED

#include <mizuiro/color/format_is_static.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>

namespace mizuiro
{
namespace image
{

MIZUIRO_DETAIL_IGNORE_EFFCPP

template<
	typename Format
>
struct format_is_static
:
mizuiro::color::format_is_static<
	typename Format::color_format
>
{
};

MIZUIRO_DETAIL_POP_WARNING

}
}

#endif
