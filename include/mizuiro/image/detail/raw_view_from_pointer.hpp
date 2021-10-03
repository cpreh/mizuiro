//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_DETAIL_RAW_VIEW_FROM_POINTER_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_RAW_VIEW_FROM_POINTER_HPP_INCLUDED

#include <mizuiro/access/raw.hpp>
#include <mizuiro/detail/const_from_pointer.hpp>
#include <mizuiro/image/pitch_view_impl.hpp>


namespace mizuiro::image::detail
{

template<
	typename Format,
	typename Pointer
>
using raw_view_from_pointer
=
mizuiro::image::pitch_view<
	mizuiro::access::raw,
	Format,
	typename mizuiro::detail::const_from_pointer<
		Pointer
	>::type
>;

}

#endif
