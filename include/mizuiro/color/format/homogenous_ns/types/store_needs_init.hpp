//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_HOMOGENOUS_NS_TYPES_STORE_NEEDS_INIT_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_HOMOGENOUS_NS_TYPES_STORE_NEEDS_INIT_HPP_INCLUDED

#include <mizuiro/color/format/homogenous_ns/tag.hpp>
#include <mizuiro/color/types/store_needs_init_ns/tag.hpp>
#include <mizuiro/mpl/false.hpp>


namespace mizuiro
{
namespace color
{
namespace types
{
namespace store_needs_init_ns
{

template<
	typename Format
>
mizuiro::mpl::false_
store_needs_init_adl(
	mizuiro::color::types::store_needs_init_ns::tag,
	mizuiro::color::format::homogenous_ns::tag<
		Format
	>
);

}
}
}
}

#endif
