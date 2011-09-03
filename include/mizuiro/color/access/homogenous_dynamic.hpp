//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_ACCESS_HOMOGENOUS_DYNAMIC_HPP_INCLUDED
#define MIZUIRO_COLOR_ACCESS_HOMOGENOUS_DYNAMIC_HPP_INCLUDED

#include <mizuiro/color/access/channel_index.hpp>
#include <mizuiro/color/access/compare_channels.hpp>
#include <mizuiro/color/access/dynamic_index.hpp>
#include <mizuiro/color/access/has_channel.hpp>
#include <mizuiro/color/access/is_last_channel.hpp>
#include <mizuiro/color/access/layout.hpp>
#include <mizuiro/color/channel/is_channel.hpp>
#include <mizuiro/color/detail/invalid_dynamic_index.hpp>
#include <mizuiro/color/format_store.hpp>
#include <mizuiro/color/is_homogenous_dynamic.hpp>
#include <mizuiro/size_type.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/not.hpp>
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
struct channel_index<
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
		color::format_store<Format> const &_format,
		Channel const &_channel
	)
	{
		return
			_format.get()->indices[
				color::access::dynamic_index<
					Format,
					Channel
				>::execute(
					_format,
					_channel
				)
			];
	}
};

template<
	typename Format,
	typename Channel
>
struct channel_index<
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
		color::format_store<Format> const &_format,
		Channel const &_channel
	)
	{
		return
			_format.get()->indices[
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
		color::format_store<Format> const &_format
	)
	{
		return
			_format.get()->order;
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
		color::format_store<Format> const &_format,
		Channel const &_channel
	)
	{
		return
			_format.get()->order.back()
			== _channel;
	}
};

template<
	typename Format,
	typename Channel
>
struct compare_channels<
	Format,
	Channel,
	typename boost::enable_if<
		mizuiro::color::is_homogenous_dynamic<
			Format
		>
	>::type
>
{
	template<
		typename OtherChannel
	>
	static
	bool
	execute(
		color::format_store<
			Format
		> const &_format,
		OtherChannel const &_other
	)
	{
		return
			_other
			==
			color::access::dynamic_index<
				Format,
				Channel
			>::execute(
				_format,
				Channel()
			);
	}
};

template<
	typename Format,
	typename StaticChannel
>
struct has_channel<
	Format,
	StaticChannel,
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
		color::format_store<
			Format
		> const &_format
	)
	{
		return
			_format.get()->indices[
				color::access::dynamic_index<
					Format,
					StaticChannel
				>::execute(
					_format,
					StaticChannel()
				)
			]
			!=
			color::detail::invalid_dynamic_index<
				typename Format::channel_index_array::value_type
>
			();
	}
};

}
}
}

#endif
