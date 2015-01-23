//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_HETEROGENOUS_NS_STORE_UNIT_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_HETEROGENOUS_NS_STORE_UNIT_HPP_INCLUDED

#include <mizuiro/color/format/heterogenous_ns/store.hpp>
#include <mizuiro/color/format/heterogenous_ns/tag.hpp>
#include <mizuiro/color/types/store.hpp>
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
mizuiro::color::types::store<
	Format
>
store_unit_adl(
	mizuiro::color::types::store_unit_ns::tag,
	mizuiro::color::format::heterogenous_ns::tag<
		Format
	>
);

}
}
}
}

#endif
