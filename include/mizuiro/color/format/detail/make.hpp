//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_DETAIL_MAKE_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_DETAIL_MAKE_HPP_INCLUDED

#include <mizuiro/color/types/needs_format_store.hpp>
#include <mizuiro/detail/ref_store.hpp>


namespace mizuiro::color::format::detail
{

template<
	typename Format,
	template<
		typename,
		template<
			typename
		> class,
		typename
	> class Inner
>
using
make
=
Inner<
	Format,
	mizuiro::color::types::needs_format_store,
	mizuiro::detail::ref_store
>;

}

#endif
