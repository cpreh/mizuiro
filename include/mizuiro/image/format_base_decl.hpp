//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_BASE_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_BASE_DECL_HPP_INCLUDED

#include <mizuiro/image/format_is_static.hpp>
#include <mizuiro/image/format_store_decl.hpp>
#include <boost/utility/enable_if.hpp>

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
	image::format_store
	image::format_is_static,
>
{
};

}
}

#endif
