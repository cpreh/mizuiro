#ifndef MIZUIRO_COLOR_CONVERT_DETAIL_COPY_OR_MAX_ALPHA_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERT_DETAIL_COPY_OR_MAX_ALPHA_HPP_INCLUDED

#include <mizuiro/color/has_channel.hpp>
#include <mizuiro/color/channel/alpha.hpp>
#include <mizuiro/color/convert/detail/max_channel.hpp>
#include <mizuiro/color/convert/detail/copy_and_convert_channel.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/or.hpp>
#include <boost/mpl/not.hpp>

namespace mizuiro
{
namespace color
{
namespace detail
{
// source and destinatin have an alpha channel, so convert
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
			Src,
			channel::alpha
		>,
		has_channel
		<
			Dest,
			channel::alpha
		>
	>,
	void
>::type
copy_or_max_alpha(
	Src const &src,
	Dest &d)
{
	copy_and_convert_channel
	<
		channel::alpha,
		// FIXME: do we want float here?
		float
	>();
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
				Src,
				channel::alpha
			>
		>,
		has_channel
		<
			Dest,
			channel::alpha
		>
	>,
	void
>::type
copy_or_max_alpha(
	Src const &,
	Dest &d)
{
	max_alpha(d);
}

// both colors do not have an alpha channel or dest doesn't have one, so do nothing
template
<
	class Src,
	class Dest
>
typename
boost::enable_if
<
	boost::mpl::or
	<
		boost::mpl::not_
		<
			boost::mpl::or_
			<
				has_channel
				<
					Src,
					channel::alpha
				>,
				has_channel
				<
					Dest,
					channel::alpha
				>
			>
		>,
		boost::mpl::not_
		<
			has_channel
			<
				Dest,
				channel::alpha
			>
		>
	>,
	void
>::type
copy_or_max_alpha(Src const &,Dest &)
{
}
}
}
}

#endif
