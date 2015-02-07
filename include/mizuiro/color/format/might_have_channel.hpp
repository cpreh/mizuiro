//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_MIGHT_HAVE_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_MIGHT_HAVE_CHANNEL_HPP_INCLUDED

#include <mizuiro/color/format/has_channel_static.hpp>
#include <mizuiro/color/format/detail/has_channel_constexpr.hpp>
#include <mizuiro/mpl/bool.hpp>


namespace mizuiro
{
namespace color
{
namespace format
{

template<
	typename Format,
	typename Channel
>
using
might_have_channel
=
mizuiro::mpl::bool_<
	!mizuiro::color::format::has_channel_static<
		Format,
		Channel
	>::value
	&&
	!mizuiro::color::format::detail::has_channel_constexpr<
		Format,
		Channel
	>::value
>;

}
}
}

#endif