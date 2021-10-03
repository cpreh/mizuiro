//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_SAME_CHANNEL_VALUE_TYPES_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_SAME_CHANNEL_VALUE_TYPES_HPP_INCLUDED

#include <mizuiro/color/format/detail/same_channel_value_type.hpp>
#include <mizuiro/color/types/static_channels.hpp>
#include <fcppt/mpl/arg.hpp>
#include <fcppt/mpl/bind.hpp>
#include <fcppt/mpl/constant.hpp>
#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/list/all_of.hpp>


namespace mizuiro::color::format
{

/**
\brief Checks if all channel values types of Layout1 are the same in Layout2
*/
template<
	typename Format1,
	typename Format2
>
using same_channel_value_types
=
fcppt::mpl::list::all_of<
	mizuiro::color::types::static_channels<
		Format1
	>,
	fcppt::mpl::bind<
		fcppt::mpl::lambda<
			mizuiro::color::format::detail::same_channel_value_type
		>,
		fcppt::mpl::constant<
			Format1
		>,
		fcppt::mpl::constant<
			Format2
		>,
		fcppt::mpl::arg<1>
	>
>;

}

#endif
