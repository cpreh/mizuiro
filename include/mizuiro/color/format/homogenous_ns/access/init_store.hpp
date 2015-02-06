//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_HOMOGENOUS_NS_ACCESS_INIT_STORE_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_HOMOGENOUS_NS_ACCESS_INIT_STORE_HPP_INCLUDED

#include <mizuiro/color/access/init_store_ns/tag.hpp>
#include <mizuiro/color/format/homogenous_ns/tag.hpp>
#include <mizuiro/color/types/store.hpp>


namespace mizuiro
{
namespace color
{
namespace access
{
namespace init_store_ns
{

template<
	typename Format
>
mizuiro::color::types::store<
	Format
>
init_store_adl(
	mizuiro::color::access::init_store_ns::tag,
	mizuiro::color::format::homogenous_ns::tag<
		Format
	>
)
{
	return
		mizuiro::color::types::store<
			Format
		>();
}

}
}
}
}

#endif
