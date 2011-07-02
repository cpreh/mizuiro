//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_ARGUMENT_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_ARGUMENT_HPP_INCLUDED

#include <mizuiro/image/format_is_static.hpp>
#include <mizuiro/image/format_store_impl.hpp>
#include <mizuiro/detail/format_argument.hpp>

namespace mizuiro
{
namespace image 
{

template<
	typename Format
>
struct format_argument
:
mizuiro::detail::format_argument<
	Format,
	image::format_is_static<
		Format
	>,
	image::format_store<
		Format
	>
>
{
};

}
}

#endif
