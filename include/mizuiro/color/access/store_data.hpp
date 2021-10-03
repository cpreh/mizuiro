//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_ACCESS_STORE_DATA_HPP_INCLUDED
#define MIZUIRO_COLOR_ACCESS_STORE_DATA_HPP_INCLUDED

#include <mizuiro/apply_const.hpp>
#include <mizuiro/access/normal.hpp>
#include <mizuiro/color/access/store_data_ns/tag.hpp>
#include <mizuiro/color/format/make_tag_of.hpp>
#include <mizuiro/color/format/store_fwd.hpp>
#include <mizuiro/color/types/pointer.hpp>
#include <mizuiro/color/types/store.hpp>


namespace mizuiro::color::access
{

template<
	typename Constness,
	typename Format
>
inline
mizuiro::color::types::pointer<
	mizuiro::access::normal,
	Format,
	Constness
>
store_data(
	mizuiro::color::format::store<
		Format
	> const &_format,
	mizuiro::apply_const<
		mizuiro::color::types::store<
			Format
		> &,
		Constness
	> _store
)
{
	return
		store_data_adl(
			mizuiro::color::access::store_data_ns::tag(),
			mizuiro::color::format::make_tag_of<
				Format
			>(),
			_format,
			Constness{},
			_store
		);
}

}

#endif
