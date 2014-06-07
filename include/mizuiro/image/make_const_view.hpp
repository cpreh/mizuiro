//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_MAKE_CONST_VIEW_HPP_INCLUDED
#define MIZUIRO_IMAGE_MAKE_CONST_VIEW_HPP_INCLUDED

#include <mizuiro/image/const_view.hpp>


namespace mizuiro
{
namespace image
{

template<
	typename View
>
typename
mizuiro::image::const_view<
	View
>::type const
make_const_view(
	View const &_view
)
{
	return
		typename
		mizuiro::image::const_view<
			View
		>::type(
			_view
		);
}

}
}

#endif
