//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_INIT_DETAIL_IS_SINGLE_VALUE_HPP_INCLUDED
#define MIZUIRO_COLOR_INIT_DETAIL_IS_SINGLE_VALUE_HPP_INCLUDED

#include <mizuiro/color/init/detail/channel_percentage_fwd.hpp>
#include <mizuiro/color/init/detail/channel_value_fwd.hpp>
#include <boost/type_traits/integral_constant.hpp>

namespace mizuiro
{
namespace color
{
namespace init
{
namespace detail
{

template<
	typename T
>
struct is_single_value
:
boost::false_type
{};

template<
	typename Value,
	typename Channel
>
struct is_single_value<
	detail::channel_value<
		Value,
		Channel
	>
>
:
boost::true_type
{};

template<
	typename Value,
	typename Channel
>
struct is_single_value<
	detail::channel_percentage<
		Value,
		Channel
	>
>
:
boost::true_type
{};

}
}
}
}

#endif
