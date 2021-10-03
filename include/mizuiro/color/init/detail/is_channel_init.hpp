//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_INIT_DETAIL_IS_CHANNEL_INIT_HPP_INCLUDED
#define MIZUIRO_COLOR_INIT_DETAIL_IS_CHANNEL_INIT_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace mizuiro::color::init::detail
{

template<
	typename Channel,
	typename Type
>
using
is_channel_init
=
std::is_same<
	typename
	Type::channel_type,
	Channel
>;

}

#endif
