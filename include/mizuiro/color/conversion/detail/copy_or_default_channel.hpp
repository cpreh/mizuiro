//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERSION_DETAIL_COPY_OR_DEFAULT_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERSION_DETAIL_COPY_OR_DEFAULT_CHANNEL_HPP_INCLUDED

#include <mizuiro/color/access/has_channel.hpp>
#include <mizuiro/color/conversion/detail/channel_to_min.hpp>
#include <mizuiro/color/conversion/detail/copy_and_convert_channel.hpp>
#include <mizuiro/color/types/has_channel_static.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/not.hpp>
#include <boost/utility/enable_if.hpp>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace conversion
{
namespace detail
{

template
<
	typename DefaultAction,
	typename Channel,
	typename Src,
	typename Dest
>
typename boost::enable_if<
	boost::mpl::and_<
		mizuiro::color::types::has_channel_static<
			typename Src::format,
			Channel
		>,
		mizuiro::color::types::has_channel_static<
			typename Dest::format,
			Channel
		>
	>,
	void
>::type
copy_or_default_channel(
	DefaultAction const &_default_action,
	Channel const &_channel,
	Src const &_src,
	Dest &_dest
)
{
	if(
		!mizuiro::color::access::has_channel(
			_dest.format_store(),
			_channel
		)
	)
		return;

	if(
		mizuiro::color::access::has_channel(
			_src.format_store(),
			_channel
		)
	)
		mizuiro::color::conversion::detail::copy_and_convert_channel<
			float
		>(
			_channel,
			_src,
			_dest
		);
	else
		_default_action(
			_channel
		);
}

template<
	typename DefaultAction,
	typename Channel,
	typename Src,
	typename Dest
>
typename boost::enable_if<
	boost::mpl::and_<
		boost::mpl::not_<
			mizuiro::color::types::has_channel_static<
				typename Src::format,
				Channel
			>
		>,
		mizuiro::color::types::has_channel_static<
			typename Dest::format,
			Channel
		>
	>,
	void
>::type
copy_or_default_channel(
	DefaultAction const &_default_action,
	Channel const &_channel,
	Src const &,
	Dest &
)
{
	_default_action(
		_channel
	);
}

template<
	typename DefaultAction,
	typename Channel,
	typename Src,
	typename Dest
>
typename boost::enable_if<
	boost::mpl::not_<
		mizuiro::color::types::has_channel_static<
			typename Dest::format,
			Channel
		>
	>,
	void
>::type
copy_or_default_channel(
	DefaultAction const &,
	Channel const &,
	Src const &,
	Dest &
)
{
}

}
}
}
}

#endif
