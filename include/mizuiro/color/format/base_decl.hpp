//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_BASE_DECL_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_BASE_DECL_HPP_INCLUDED

#include <mizuiro/color/format/store_decl.hpp>
#include <mizuiro/color/types/needs_format_store.hpp>
#include <mizuiro/detail/format_base_decl.hpp>


namespace mizuiro
{
namespace color
{
namespace format
{

template<
	typename Format
>
using base
=
mizuiro::detail::format_base<
	Format,
	mizuiro::color::format::store,
	mizuiro::color::types::needs_format_store
>;

}
}
}

#endif
