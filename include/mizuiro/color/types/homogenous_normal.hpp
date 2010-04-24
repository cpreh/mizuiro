#ifndef MIZUIRO_COLOR_TYPES_HOMOGENOUS_NORMAL_HPP_INCLUDED
#define MIZUIRO_COLOR_TYPES_HOMOGENOUS_NORMAL_HPP_INCLUDED

#include <mizuiro/color/types/pointer.hpp>
#include <mizuiro/color/types/channel_value.hpp>
#include <mizuiro/color/types/channel_reference.hpp>
#include <mizuiro/color/types/store.hpp>
#include <mizuiro/color/homogenous_fwd.hpp>
#include <mizuiro/access/normal.hpp>
#include <mizuiro/detail/apply_const.hpp>
#include <fcppt/tr1/array.hpp>
#include <boost/mpl/size.hpp>

namespace mizuiro
{
namespace color
{
namespace types
{

template<
	typename ChannelType,
	typename Layout,
	typename Constness
>
struct pointer<
	::mizuiro::access::normal,
	color::homogenous<
		ChannelType,
		Layout
	>,
	Constness
>
:
mizuiro::detail::apply_const<
	ChannelType *,
	Constness
>
{};

template<
	typename ChannelType,
	typename Layout,
	typename Channel
>
struct channel_value<
	::mizuiro::access::normal,
	color::homogenous<
		ChannelType,
		Layout
	>,
	Channel
>
{
	typedef ChannelType type;
};

template<
	typename ChannelType,
	typename Layout,
	typename Channel,
	typename Constness
>
struct channel_reference<
	::mizuiro::access::normal,
	color::homogenous<
		ChannelType,
		Layout
	>,
	Channel,
	Constness
>
:
mizuiro::detail::apply_const<
	ChannelType &,
	Constness
>
{};

template<
	typename ChannelType,
	typename Layout
>
struct store<
	::mizuiro::access::normal,
	color::homogenous<
		ChannelType,
		Layout
	>
>
{
	typedef std::tr1::array<
		ChannelType,
		boost::mpl::size<
			typename Layout::order
		>::value
	> type;
};

}
}
}

#endif
