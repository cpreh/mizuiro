//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_INIT_DETAIL_CONTAINS_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_INIT_DETAIL_CONTAINS_CHANNEL_HPP_INCLUDED

#include <mizuiro/color/init/detail/is_channel_init.hpp>
#include <fcppt/mpl/arg.hpp>
#include <fcppt/mpl/bind.hpp>
#include <fcppt/mpl/constant.hpp>
#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/list/any_of.hpp>

namespace mizuiro::color::init::detail
{

template <typename Types, typename Channel>
using contains_channel = fcppt::mpl::list::any_of<
    Types,
    fcppt::mpl::bind<
        fcppt::mpl::lambda<mizuiro::color::init::detail::is_channel_init>,
        fcppt::mpl::constant<Channel>,
        fcppt::mpl::arg<1>>>;

}

#endif
