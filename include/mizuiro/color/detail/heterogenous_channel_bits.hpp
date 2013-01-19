//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_DETAIL_HETEROGENOUS_CHANNEL_BITS_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_HETEROGENOUS_CHANNEL_BITS_HPP_INCLUDED

#include <mizuiro/integral_size.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/index_of.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/mpl/at.hpp>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace detail
{

MIZUIRO_DETAIL_IGNORE_EFFCPP

template<
	typename Format,
	typename Channel
>
struct heterogenous_channel_bits
:
mizuiro::integral_size<
	boost::mpl::at<
		typename Format::channel_bits,
		typename mizuiro::detail::index_of<
			typename Format::layout::order,
			Channel
		>::type
	>::type::value
>
{
};

MIZUIRO_DETAIL_POP_WARNING

}
}
}

#endif
