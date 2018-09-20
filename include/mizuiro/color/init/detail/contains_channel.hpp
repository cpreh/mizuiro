//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_INIT_DETAIL_CONTAINS_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_INIT_DETAIL_CONTAINS_CHANNEL_HPP_INCLUDED

#include <mizuiro/color/init/detail/is_channel_init.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/algorithms/find.hpp>
#include <brigand/functions/lambda/bind.hpp>
#include <brigand/types/args.hpp>
#include <fcppt/config/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace init
{
namespace detail
{

template<
	typename Types,
	typename Channel
>
using
contains_channel
=
brigand::found<
	Types,
	brigand::bind<
		mizuiro::color::init::detail::is_channel_init,
		Channel,
		brigand::_1
	>
>;

}
}
}
}

#endif
