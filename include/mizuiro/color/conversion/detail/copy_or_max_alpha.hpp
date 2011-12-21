//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERSION_DETAIL_COPY_OR_MAX_ALPHA_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERSION_DETAIL_COPY_OR_MAX_ALPHA_HPP_INCLUDED

#include <mizuiro/color/access/has_channel.hpp>
#include <mizuiro/color/channel/alpha.hpp>
#include <mizuiro/color/conversion/detail/channel_to_max.hpp>
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
	typename Src,
	typename Dest
>
typename boost::enable_if<
	boost::mpl::and_<
		mizuiro::color::types::has_channel_static<
			typename Src::format,
			mizuiro::color::channel::alpha
		>,
		mizuiro::color::types::has_channel_static<
			typename Dest::format,
			mizuiro::color::channel::alpha
		>
	>,
	void
>::type
copy_or_max_alpha(
	Src const &_src,
	Dest &_dest
)
{
	if(
		!color::access::has_channel<
			typename Dest::format,
			channel::alpha
		>::execute(
			_dest.format_store()
		)
	)
		return;

	if(
		color::access::has_channel<
			typename Src::format,
			channel::alpha
		>::execute(
			_src.format_store()
		)
	)
		conversion::detail::copy_and_convert_channel<
			float
		>
		(
			channel::alpha(),
			_src,
			_dest
		);
	else
		conversion::detail::channel_to_max
		(
			_dest,
			channel::alpha()
		);

}

template<
	typename Src,
	typename Dest
>
typename boost::enable_if<
	boost::mpl::and_<
		boost::mpl::not_<
			mizuiro::color::types::has_channel_static<
				typename Src::format,
				mizuiro::color::channel::alpha
			>
		>,
		mizuiro::color::types::has_channel_static<
			typename Dest::format,
			mizuiro::color::channel::alpha
		>
	>,
	void
>::type
copy_or_max_alpha(
	Src const &,
	Dest &_dest
)
{
	conversion::detail::channel_to_max
	(
		_dest,
		channel::alpha()
	);
}

template<
	typename Src,
	typename Dest
>
typename boost::enable_if<
	boost::mpl::not_<
		mizuiro::color::types::has_channel_static<
			typename Dest::format,
			mizuiro::color::channel::alpha
		>
	>,
	void
>::type
copy_or_max_alpha(
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
