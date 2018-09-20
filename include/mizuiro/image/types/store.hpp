//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_TYPES_STORE_HPP_INCLUDED
#define MIZUIRO_IMAGE_TYPES_STORE_HPP_INCLUDED

#include <mizuiro/image/format/make_tag_of.hpp>
#include <mizuiro/image/types/store_ns/tag.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace mizuiro
{
namespace image
{
namespace types
{

template<
	typename Access,
	typename Format
>
using
store
=
decltype(
	store_adl(
		std::declval<
			mizuiro::image::types::store_ns::tag
		>(),
		std::declval<
			Access
		>(),
		mizuiro::image::format::make_tag_of<
			Format
		>()
	)
);

}
}
}

#endif
