//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_STATIC_NS_NEEDS_FORMAT_STORE_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_STATIC_NS_NEEDS_FORMAT_STORE_HPP_INCLUDED

#include <mizuiro/color/format/static_ns/tag.hpp>
#include <mizuiro/color/types/needs_format_store_ns/tag.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <type_traits>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace types
{
namespace needs_format_store_ns
{

template<
	typename Format
>
std::false_type
needs_format_store_adl(
	mizuiro::color::types::needs_format_store_ns::tag,
	mizuiro::color::format::static_ns::tag<
		Format
	>
);

}
}
}
}

#endif
