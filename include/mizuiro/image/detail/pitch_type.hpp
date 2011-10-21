//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_DETAIL_PITCH_TYPE_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_PITCH_TYPE_HPP_INCLUDED

#include <mizuiro/difference_type.hpp>
#include <mizuiro/size_type.hpp>
#include <mizuiro/image/dimension_decl.hpp>


namespace mizuiro
{
namespace image
{
namespace detail
{

template<
	typename T
>
struct pitch_type;

template<
	mizuiro::size_type Dim
>
struct pitch_type<
	dimension<
		Dim,
		mizuiro::size_type
	>
>
{
	typedef dimension<
		Dim - 1,
		mizuiro::difference_type
	> type;
};

template<
	typename T
>
struct pitch_type<
	dimension<
		0,
		T
	>
>
{};

}
}
}

#endif
