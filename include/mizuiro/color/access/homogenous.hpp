//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_ACCESS_HOMOGENOUS_HPP_INCLUDED
#define MIZUIRO_COLOR_ACCESS_HOMOGENOUS_HPP_INCLUDED

#include <mizuiro/color/format_store_fwd.hpp>
#include <mizuiro/color/is_homogenous.hpp>
#include <mizuiro/color/access/channel_max.hpp>
#include <mizuiro/color/access/channel_min.hpp>
#include <mizuiro/color/detail/full_channel_max.hpp>
#include <mizuiro/color/detail/full_channel_min.hpp>
#include <mizuiro/color/types/channel_value.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace access
{

template<
	typename Format,
	typename Channel
>
struct channel_min<
	Format,
	Channel,
	typename boost::enable_if<
		mizuiro::color::is_homogenous<
			Format
		>
	>::type
>
{
	static
	typename mizuiro::color::types::channel_value<
		Format,
		Channel
	>::type
	execute(
		mizuiro::color::format_store<
			Format
		> const &,
		Channel const &
	)
	{
		return
			mizuiro::color::detail::full_channel_min<
				typename Format::channel_type
			>();
	}
};

template<
	typename Format,
	typename Channel
>
struct channel_max<
	Format,
	Channel,
	typename boost::enable_if<
		mizuiro::color::is_homogenous<
			Format
		>
	>::type
>
{
	static
	typename mizuiro::color::types::channel_value<
		Format,
		Channel
	>::type
	execute(
		mizuiro::color::format_store<
			Format
		> const &,
		Channel const &
	)
	{
		return
			mizuiro::color::detail::full_channel_max<
				typename Format::channel_type
			>();
	}
};

}
}
}

#endif
