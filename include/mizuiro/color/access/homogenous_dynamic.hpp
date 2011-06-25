//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_ACCESS_HOMOGENOUS_DYNAMIC_HPP_INCLUDED
#define MIZUIRO_COLOR_ACCESS_HOMOGENOUS_DYNAMIC_HPP_INCLUDED

#include <mizuiro/color/access/channel_index.hpp>
#include <mizuiro/color/access/dynamic_index.hpp>
#include <mizuiro/color/access/is_last_channel.hpp>
#include <mizuiro/color/access/layout.hpp>
#include <mizuiro/color/channel/is_channel.hpp>
#include <mizuiro/color/is_homogenous_dynamic.hpp>
#include <mizuiro/size_type.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/not.hpp>
#include <boost/utility/enable_if.hpp>

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
		boost::mpl::and_<
			mizuiro::color::channel::is_channel<
				Channel
			>,
			mizuiro::color::is_homogenous_dynamic<
				Format
			>
		>
	>::type
>
{
	static
	mizuiro::size_type
	execute(
		Access const &_access,
		Format const *const _format,
		Channel const &_channel
	)
	{
		return
			_format->indices[
				color::access::dynamic_index<
					Access,
					Format,
					Channel
				>::execute(
					_access,
					*_format,
					_channel
				)
			];
	}
};

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
		boost::mpl::and_<
			boost::mpl::not_<
				mizuiro::color::channel::is_channel<
					Channel
				>
			>,
			mizuiro::color::is_homogenous_dynamic<
				Format
			>
		>
	>::type
>
{
	static
	mizuiro::size_type
	execute(
		Access const &,
		Format const *const _format,
		Channel const &_channel
	)
	{
		return
			_format->indices[
				_channel
			];
	}
};

template<
	typename Format
>
struct layout<
	Format,	
	typename boost::enable_if<
		mizuiro::color::is_homogenous_dynamic<
			Format
		>
	>::type
>
{
	static
	typename Format::layout const &
	execute(
		Format const *const _format
	)
	{
		return
			_format->order;
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
		mizuiro::color::is_homogenous_dynamic<
			Format
		>
	>::type
>
{
	static
	bool
	execute(
		Format const *const _format,
		Channel const &_channel
	)
	{
		return
			_format->order.back()
			== _channel;
	}
};

}
}
}

#endif
