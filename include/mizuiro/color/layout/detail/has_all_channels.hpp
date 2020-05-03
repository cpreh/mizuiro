//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_LAYOUT_DETAIL_HAS_ALL_CHANNELS_HPP_INCLUDED
#define MIZUIRO_COLOR_LAYOUT_DETAIL_HAS_ALL_CHANNELS_HPP_INCLUDED

#include <mizuiro/color/layout/detail/has_channel.hpp>
#include <fcppt/type_traits/to_bool.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <fcppt/config/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace layout
{
namespace detail
{

template<
	typename Order1,
	typename Order2
>
using has_all_channels
=
fcppt::type_traits::to_bool<
	metal::all_of<
		Order1,
		metal::bind<
			metal::trait<
				mizuiro::color::layout::detail::has_channel
			>,
			metal::always<
				Order2
			>,
			metal::_1
		>
	>
>;

}
}
}
}

#endif
