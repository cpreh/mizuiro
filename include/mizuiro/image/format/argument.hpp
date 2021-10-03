//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_ARGUMENT_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_ARGUMENT_HPP_INCLUDED

#include <mizuiro/detail/format_argument.hpp>
#include <mizuiro/image/format/detail/make.hpp>


namespace mizuiro::image::format
{

template<
	typename Format
>
using argument
=
mizuiro::image::format::detail::make<
	Format,
	mizuiro::detail::format_argument
>;

}

#endif
