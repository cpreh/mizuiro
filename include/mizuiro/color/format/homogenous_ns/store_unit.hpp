//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_HOMOGENOUS_NS_STORE_UNIT_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_HOMOGENOUS_NS_STORE_UNIT_HPP_INCLUDED

#include <mizuiro/color/format/homogenous_ns/tag.hpp>
#include <mizuiro/color/types/store_unit_ns/tag.hpp>


namespace mizuiro
{
namespace color
{
namespace types
{
namespace store_unit_ns
{

template<
	typename Format
>
typename
Format::channel_type
store_unit_adl(
	mizuiro::color::types::store_unit_ns::tag,
	mizuiro::color::format::homogenous_ns::tag<
		Format
	>
);

}
}
}
}

#endif
