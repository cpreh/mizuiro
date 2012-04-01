//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_ARGUMENT_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_ARGUMENT_HPP_INCLUDED

#include <mizuiro/color/format_is_static.hpp>
#include <mizuiro/color/format_store_impl.hpp>
#include <mizuiro/detail/format_argument.hpp>
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
struct format_argument
:
mizuiro::detail::format_argument<
	Format,
	color::format_is_static<
		Format
	>,
	color::format_store<
		Format
	>
>
{
};

MIZUIRO_DETAIL_POP_WARNING

}
}

#endif
