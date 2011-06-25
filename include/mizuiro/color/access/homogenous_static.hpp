//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_ACCESS_HOMOGENOUS_STATIC_HPP_INCLUDED
#define MIZUIRO_COLOR_ACCESS_HOMOGENOUS_STATIC_HPP_INCLUDED

#include <mizuiro/color/access/channel_index.hpp>
#include <mizuiro/color/access/is_last_channel.hpp>
#include <mizuiro/color/access/layout.hpp>
#include <mizuiro/color/is_homogenous_static.hpp>
#include <mizuiro/detail/index_of.hpp>
#include <mizuiro/size_type.hpp>
#include <boost/fusion/adapted/mpl.hpp>
#include <boost/mpl/size.hpp>

namespace mizuiro
{
namespace color
{
namespace access
{

template<
	typename Access,
	typename Format,
	typename Channel
>
struct channel_index<
	Access,
	Format,
	Channel,
	typename boost::enable_if<
		mizuiro::color::is_homogenous_static<
			Format
		>
	>::type
>
{
	static
	mizuiro::size_type
	execute(
		Access const &,
		Format const *,
		Channel const &
	)
	{
		return
			mizuiro::detail::index_of<
				typename Format::layout::order,
				Channel
			>::value;
	}
};

template<
	typename Format
>
struct layout<
	Format,	
	typename boost::enable_if<
		mizuiro::color::is_homogenous_static<
			Format
		>
	>::type
>
{
	static
	typename Format::layout::order const
	execute(
		Format const *
	)
	{
		return typename Format::layout::order();
	}
};

template<
	typename Format,
	typename Channel
>
struct is_last_channel<
	Format,
	Channel,
	typename boost::enable_if<
		mizuiro::color::is_homogenous_static<
			Format
		>
	>::type
>
{
	static
	bool
	execute(
		Format const *,
		Channel const &
	)
	{
		return
			mizuiro::detail::index_of<
				typename Format::layout::order,
				Channel
			>::value + 1
			==
			boost::mpl::size<
				typename Format::layout::order
			>::value;
	}
};

}
}
}

#endif
