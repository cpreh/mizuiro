//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_DYNAMIC_NS_CHANNEL_INDEX_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_DYNAMIC_NS_CHANNEL_INDEX_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <mizuiro/color/access/channel_index_ns/tag.hpp>
#include <mizuiro/color/detail/static_to_dynamic_channel.hpp>
#include <mizuiro/color/format/store.hpp>
#include <mizuiro/color/format/dynamic_ns/tag.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/fusion/adapted/mpl.hpp>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace access
{
namespace channel_index_ns
{

template<
	typename Format,
	typename Channel
>
mizuiro::size_type
channel_index_adl(
	mizuiro::color::access::channel_index_ns::tag,
	mizuiro::color::format::dynamic_ns::tag<
		Format
	>,
	mizuiro::color::format::store<
		Format
	> const &_format,
	Channel const &_channel
)
{
	return
		_format.get()->indices[
			static_cast<
				mizuiro::size_type
			>(
				mizuiro::color::detail::static_to_dynamic_channel<
					Format
				>(
					_channel
				)
			)
		];
}

/*
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
		mizuiro::color::format_store<Format> const &_format,
		Channel const &_channel
	)
	{
		return
			_format.get()->indices[
				static_cast<
					mizuiro::size_type
				>(
					_channel
				)
			];
	}
};
*/

}
}
}
}

#endif
