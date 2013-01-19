//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_BASE_DECL_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_BASE_DECL_HPP_INCLUDED

#include <mizuiro/color/format_is_static.hpp>
#include <mizuiro/color/format_store_decl.hpp>
#include <mizuiro/detail/format_base_decl.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>


namespace mizuiro
{
namespace color
{

MIZUIRO_DETAIL_IGNORE_EFFCPP

template<
	typename Format
>
struct format_base
:
mizuiro::detail::format_base<
	Format,
	mizuiro::color::format_store,
	mizuiro::color::format_is_static
>
{
};

MIZUIRO_DETAIL_POP_WARNING

}
}

#endif
