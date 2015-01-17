//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_CONST_VIEW_HPP_INCLUDED
#define MIZUIRO_IMAGE_CONST_VIEW_HPP_INCLUDED

#include <mizuiro/image/detail/const_view.hpp>


namespace mizuiro
{
namespace image
{

template<
	typename View
>
using
const_view
=
typename
mizuiro::image::detail::const_view<
	View
>::type;

}
}

#endif
