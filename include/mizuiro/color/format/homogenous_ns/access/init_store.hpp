//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_HOMOGENOUS_NS_ACCESS_INIT_STORE_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_HOMOGENOUS_NS_ACCESS_INIT_STORE_HPP_INCLUDED

#include <mizuiro/color/access/init_store_ns/tag.hpp>
#include <mizuiro/color/format/homogenous_ns/tag.hpp>
#include <mizuiro/color/types/store.hpp>
#include <fcppt/array/init.hpp>
#include <fcppt/array/value_type.hpp>


namespace mizuiro::color::access::init_store_ns
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
		fcppt::array::init<
			mizuiro::color::types::store<
				Format
			>
		>(
			[](auto)
			{
				return
					fcppt::array::value_type<
						mizuiro::color::types::store<
							Format
						>
					>{};
			}
		);
}

}

#endif
