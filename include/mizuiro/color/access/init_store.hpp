//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_ACCESS_INIT_STORE_HPP_INCLUDED
#define MIZUIRO_COLOR_ACCESS_INIT_STORE_HPP_INCLUDED

#include <mizuiro/color/access/init_store_ns/tag.hpp>
#include <mizuiro/color/format/make_tag_of.hpp>
#include <mizuiro/color/types/store.hpp>


namespace mizuiro
{
namespace color
{
namespace access
{

template<
	typename Format
>
mizuiro::color::types::store<
	Format
>
init_store()
{
	return
		init_store_adl(
			mizuiro::color::access::init_store_ns::tag(),
			mizuiro::color::format::make_tag_of<
				Format
			>()
		);
}

}
}
}

#endif
