//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_LAYOUT_DETAIL_HAS_ALL_CHANNELS_HPP_INCLUDED
#define MIZUIRO_COLOR_LAYOUT_DETAIL_HAS_ALL_CHANNELS_HPP_INCLUDED

#include <mizuiro/color/layout/detail/has_channel.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/algorithms/all.hpp>
#include <brigand/functions/lambda/apply.hpp>
#include <brigand/functions/lambda/bind.hpp>
#include <brigand/types/args.hpp>
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
brigand::all<
	Order1,
	brigand::bind<
		mizuiro::color::layout::detail::has_channel,
		brigand::pin<
			Order2
		>,
		brigand::_1
	>
>;

}
}
}
}

#endif
