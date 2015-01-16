//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_HETEROGENOUS_NS_STORE_NEEDS_INIT_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_HETEROGENOUS_NS_STORE_NEEDS_INIT_HPP_INCLUDED

#include <mizuiro/color/format/heterogenous_ns/tag.hpp>
#include <mizuiro/color/types/store_needs_init_ns/tag.hpp>
#include <mizuiro/mpl/true.hpp>


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
mizuiro::mpl::true_
store_needs_init_adl(
	mizuiro::color::types::store_needs_init_ns::tag,
	mizuiro::color::format::heterogenous_ns::tag<
		Format
	>
);

}
}
}
}

#endif
