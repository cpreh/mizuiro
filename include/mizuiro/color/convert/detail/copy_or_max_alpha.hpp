//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERT_DETAIL_COPY_OR_MAX_ALPHA_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERT_DETAIL_COPY_OR_MAX_ALPHA_HPP_INCLUDED

#include <mizuiro/color/has_channel.hpp>
#include <mizuiro/color/channel/alpha.hpp>
#include <mizuiro/color/convert/detail/max_alpha.hpp>
#include <mizuiro/color/convert/detail/copy_and_convert_channel.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/not.hpp>

namespace mizuiro
{
namespace color
{
namespace detail
{

// source and destination have an alpha channel, so convert
template
<
	class Src,
	class Dest
>
typename
boost::enable_if
<
	boost::mpl::and_
	<
		color::has_channel
		<
			typename Src::format,
			channel::alpha
		>,
		color::has_channel
		<
			typename Dest::format,
			channel::alpha
		>
	>,
	void
>::type
copy_or_max_alpha(
	Src const &_src,
	Dest &_dest
)
{
	// FIXME!
#if 0
	color::detail::copy_and_convert_channel
	<
		channel::alpha,
		float
	>
	(
		src,
		dest
	);
#endif
}

// source doesn't have an alpha channel, but destination has, so max out destination alpha
template
<
	class Src,
	class Dest
>
typename
boost::enable_if
<
	boost::mpl::and_
	<
		boost::mpl::not_
		<
			has_channel
			<
				typename Src::format,
				channel::alpha
			>
		>,
		has_channel
		<
			typename Dest::format,
			channel::alpha
		>
	>,
	void
>::type
copy_or_max_alpha(
	Src const &,
	Dest &_dest
)
{
	detail::max_alpha(
		_dest
	);
}

// dest doesn't have an alpha channel, so do nothing
template
<
	class Src,
	class Dest
>
typename
boost::enable_if
<
	boost::mpl::not_
	<
		has_channel
		<
			typename Dest::format,
			channel::alpha
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

#endif
