//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_HETEROGENOUS_STATIC_NS_TAG_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_HETEROGENOUS_STATIC_NS_TAG_HPP_INCLUDED

#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/color/format/heterogenous_ns/tag.hpp>
#include <mizuiro/color/format/static_ns/tag.hpp>


namespace mizuiro
{
namespace color
{
namespace format
{
namespace heterogenous_static_ns
{

MIZUIRO_DETAIL_IGNORE_EFFCPP

template<
	typename Type
>
struct tag
:
	mizuiro::color::format::heterogenous_ns::tag<
		Type
	>,
	mizuiro::color::format::static_ns::tag<
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
