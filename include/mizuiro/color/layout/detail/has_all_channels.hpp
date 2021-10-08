//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_LAYOUT_DETAIL_HAS_ALL_CHANNELS_HPP_INCLUDED
#define MIZUIRO_COLOR_LAYOUT_DETAIL_HAS_ALL_CHANNELS_HPP_INCLUDED

#include <mizuiro/color/layout/detail/has_channel.hpp>
#include <fcppt/mpl/arg.hpp>
#include <fcppt/mpl/bind.hpp>
#include <fcppt/mpl/constant.hpp>
#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/list/all_of.hpp>

namespace mizuiro::color::layout::detail
{

template <typename Order1, typename Order2>
using has_all_channels = fcppt::mpl::list::all_of<
    Order1,
    fcppt::mpl::bind<
        fcppt::mpl::lambda<mizuiro::color::layout::detail::has_channel>,
        fcppt::mpl::constant<Order2>,
        fcppt::mpl::arg<1>>>;

}

#endif
