//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_DETAIL_PROMOTE_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_PROMOTE_CHANNEL_HPP_INCLUDED

#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/type_traits/promote.hpp>
#include <mizuiro/detail/external_end.hpp>

namespace mizuiro
{
namespace color
{
namespace detail
{

MIZUIRO_DETAIL_IGNORE_EFFCPP

template<
	typename T
>
struct promote_channel
:
boost::promote<
	T
>
{};

MIZUIRO_DETAIL_POP_WARNING

}
}
}

#endif
