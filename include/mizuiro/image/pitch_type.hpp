//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_PITCH_TYPE_HPP_INCLUDED
#define MIZUIRO_IMAGE_PITCH_TYPE_HPP_INCLUDED

#include <mizuiro/difference_type.hpp>
#include <mizuiro/size_type.hpp>
#include <mizuiro/image/dimension_fwd.hpp>


namespace mizuiro
{
namespace image
{

template<
	typename Type
>
struct pitch_type;

template<
	mizuiro::size_type Dim
>
struct pitch_type<
	mizuiro::image::dimension<
		Dim,
		mizuiro::size_type
	>
>
{
	typedef mizuiro::image::dimension<
		Dim - 1,
		mizuiro::difference_type
	> type;
};

template<
	typename Type
>
struct pitch_type<
	mizuiro::image::dimension<
		0,
		Type
	>
>
{
};

}
}

#endif
