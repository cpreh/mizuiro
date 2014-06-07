//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_DETAIL_IS_LAST_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_IS_LAST_CHANNEL_HPP_INCLUDED

#include <mizuiro/detail/index_of.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/size.hpp>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace detail
{

template<
	typename Format,
	typename Channel
>
struct is_last_channel
:
boost::mpl::bool_<
	mizuiro::detail::index_of<
		typename Format::layout::order,
		Channel
	>::value + 1
	==
	boost::mpl::size<
		typename Format::layout::order
	>::value
>
{};

}
}
}

#endif
