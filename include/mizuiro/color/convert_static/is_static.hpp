//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERT_STATIC_IS_STATIC_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERT_STATIC_IS_STATIC_HPP_INCLUDED

#include <mizuiro/color/format/tag_of_fwd.hpp>
#include <mizuiro/color/format/static_ns/tag.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <type_traits>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace convert_static
{

MIZUIRO_DETAIL_IGNORE_EFFCPP

template<
	typename Format
>
struct is_static
:
std::is_base_of<
	mizuiro::color::format::static_ns::tag<
		Format
	>,
	typename
	mizuiro::color::format::tag_of<
		Format
	>::type
>
{
};

MIZUIRO_DETAIL_POP_WARNING

}
}
}

#endif
