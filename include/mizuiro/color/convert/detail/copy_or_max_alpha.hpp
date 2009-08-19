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
		has_channel
		<
			typename Src::format,
			channel::alpha
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
	Src const &src,
	Dest &dest)
{
	copy_and_convert_channel
	<
		channel::alpha,
		float
	>
	(
		src,
		dest
	);
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
	Dest &d
)
{
	max_alpha(
		d
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
