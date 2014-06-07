//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_ARGUMENT_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_ARGUMENT_HPP_INCLUDED

#include <mizuiro/color/format/store_impl.hpp>
#include <mizuiro/color/types/needs_store.hpp>
#include <mizuiro/detail/format_argument.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>


namespace mizuiro
{
namespace color
{
namespace format
{

MIZUIRO_DETAIL_IGNORE_EFFCPP

template<
	typename Format
>
struct argument
:
mizuiro::detail::format_argument<
	Format,
	mizuiro::color::types::needs_store<
		Format
	>,
	mizuiro::color::format::store<
		Format
	>
>
{
};

MIZUIRO_DETAIL_POP_WARNING

}
}
}

#endif
