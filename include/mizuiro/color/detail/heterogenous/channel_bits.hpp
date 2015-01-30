//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_DETAIL_HETEROGENOUS_CHANNEL_BITS_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_HETEROGENOUS_CHANNEL_BITS_HPP_INCLUDED

#include <mizuiro/mpl/at.hpp>
#include <mizuiro/mpl/index_of.hpp>


namespace mizuiro
{
namespace color
{
namespace detail
{
namespace heterogenous
{

template<
	typename Format,
	typename Channel
>
using channel_bits
=
mizuiro::mpl::at<
	typename Format::channel_bits,
	mizuiro::mpl::index_of<
		typename Format::layout::channels,
		Channel
	>()
>;

}
}
}
}

#endif
