//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_DETAIL_DYNAMIC_CHANNEL_ARRAY_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_DYNAMIC_CHANNEL_ARRAY_HPP_INCLUDED

#include <mizuiro/array.hpp>
#include <mizuiro/size_type.hpp>
#include <mizuiro/color/detail/channel_index.hpp>


namespace mizuiro
{
namespace color
{
namespace detail
{

template<
	mizuiro::size_type Size
>
using
dynamic_channel_array
=
mizuiro::array<
	mizuiro::color::detail::channel_index,
	Size
>;

}
}
}

#endif
