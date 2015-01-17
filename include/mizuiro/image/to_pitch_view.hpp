//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_TO_PITCH_VIEW_HPP_INCLUDED
#define MIZUIRO_IMAGE_TO_PITCH_VIEW_HPP_INCLUDED

#include <mizuiro/image/pitch_view_fwd.hpp>


namespace mizuiro
{
namespace image
{

template<
	typename View
>
using
to_pitch_view
=
mizuiro::image::pitch_view<
	typename View::access,
	typename View::format,
	typename View::constness
>;

}
}

#endif
