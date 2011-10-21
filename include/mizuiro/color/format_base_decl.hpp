//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_BASE_DECL_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_BASE_DECL_HPP_INCLUDED

#include <mizuiro/color/format_is_static.hpp>
#include <mizuiro/color/format_store_decl.hpp>
#include <mizuiro/detail/format_base_decl.hpp>


namespace mizuiro
{
namespace color
{

template<
	typename Format
>
struct format_base
:
mizuiro::detail::format_base<
	Format,
	color::format_store,
	color::format_is_static
>
{
};

}
}

#endif
