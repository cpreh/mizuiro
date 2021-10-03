//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_DETAIL_HAS_CHANNEL_CONSTEXPR_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_DETAIL_HAS_CHANNEL_CONSTEXPR_HPP_INCLUDED

#include <mizuiro/color/format/detail/check_has_channel_constexpr.hpp>


namespace mizuiro::color::format::detail
{

template<
	typename Format,
	typename Channel
>
using
has_channel_constexpr
=
decltype(
	mizuiro::color::format::detail::check_has_channel_constexpr<
		Format,
		Channel
	>(
		0
	)
);

}

#endif
