//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_BASE_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_BASE_DECL_HPP_INCLUDED

#include <mizuiro/detail/format_base_decl.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/image/format/store_decl.hpp>
#include <mizuiro/image/types/needs_store.hpp>


namespace mizuiro
{
namespace image
{
namespace format
{

MIZUIRO_DETAIL_IGNORE_EFFCPP

template<
	typename Format
>
struct base
:
mizuiro::detail::format_base<
	Format,
	mizuiro::image::format::store,
	mizuiro::image::types::needs_store
>
{
};

MIZUIRO_DETAIL_POP_WARNING

}
}
}

#endif
