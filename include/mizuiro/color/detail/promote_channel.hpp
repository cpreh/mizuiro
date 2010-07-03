//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_DETAIL_PROMOTE_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_PROMOTE_CHANNEL_HPP_INCLUDED

#include <boost/type_traits/promote.hpp>

namespace mizuiro
{
namespace color
{
namespace detail
{

template<
	typename T
>
struct promote_channel
:
boost::promote<
	T
>
{};

}
}
}

#endif
