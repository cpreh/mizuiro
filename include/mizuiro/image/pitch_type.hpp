//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_PITCH_TYPE_HPP_INCLUDED
#define MIZUIRO_IMAGE_PITCH_TYPE_HPP_INCLUDED

#include <mizuiro/image/detail/pitch_type.hpp>


namespace mizuiro
{
namespace image
{

template<
	typename DimType
>
using
pitch_type
=
typename
mizuiro::image::detail::pitch_type<
	DimType
>::type;

}
}

#endif
