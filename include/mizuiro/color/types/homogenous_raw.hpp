#ifndef MIZUIRO_COLOR_TYPES_HOMOGENOUS_RAW_HPP_INCLUDED
#define MIZUIRO_COLOR_TYPES_HOMOGENOUS_RAW_HPP_INCLUDED

#include <mizuiro/color/types/pointer.hpp>
#include <mizuiro/color/types/channel_value.hpp>
#include <mizuiro/color/types/channel_reference.hpp>
#include <mizuiro/color/types/store.hpp>
#include <mizuiro/color/homogenous_fwd.hpp>
#include <mizuiro/access/raw_fwd.hpp>
#include <mizuiro/detail/apply_const.hpp>
#include <mizuiro/raw_value.hpp>
#include <fcppt/tr1/array.hpp>

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
	::mizuiro::access::raw,
	color::homogenous<
		ChannelType,
		Layout
	>,
	Constness
>
{
	typedef detail::stride_pointer<
		typename mizuiro::detail::apply_const<
			raw_pointer,
			Constness
		>::type,
		sizeof(typename Layout::channel_type)
	> type;
};

template<
	typename ChannelType,
	typename Layout,
	typename Channel
>
struct channel_value<
	::mizuiro::access::raw,
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
	::mizuiro::access::raw,
	color::homogenous<
		ChannelType,
		Layout
	>,
	Channel,
	Constness
>
{
	typedef color::channel_proxy<
		typename types::channel_value<
			::mizuiro::access::raw,
			ChannelType,
			Layout
			Channel
		>::type,
		typename types::pointer<
			::mizuiro::access::raw,
			ChannelType,
			Layout,
			Constness
		>::type
	> type;

};

template<
	typename ChannelType,
	typename Layout
>
struct store<
	::mizuiro::access::raw,
	color::homogenous<
		ChannelType,
		Layout
	>
>
{
	typedef std::tr1::array<
		raw_value,
		Layout::element_count
		* sizeof(typename Layout::channel_type)
	> store;
};

}
}
}

#endif
