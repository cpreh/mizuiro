//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_HOMOGENOUS_DYNAMIC_NS_TAG_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_HOMOGENOUS_DYNAMIC_NS_TAG_HPP_INCLUDED

#include <mizuiro/color/format/defaults_ns/tag.hpp>
#include <mizuiro/color/format/dynamic_ns/tag.hpp>
#include <mizuiro/color/format/homogenous_ns/tag.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>


namespace mizuiro
{
namespace color
{
namespace format
{
namespace homogenous_dynamic_ns
{

MIZUIRO_DETAIL_IGNORE_EFFCPP

template<
	typename Type
>
struct tag
:
	mizuiro::color::format::defaults_ns::tag<
		Type
	>,
	mizuiro::color::format::homogenous_ns::tag<
		Type
	>,
	mizuiro::color::format::dynamic_ns::tag<
		Type
	>
{
};

MIZUIRO_DETAIL_POP_WARNING

}
}
}
}

#endif
