//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_TYPES_HETEROGENOUS_HPP_INCLUDED
#define MIZUIRO_COLOR_TYPES_HETEROGENOUS_HPP_INCLUDED

#include <mizuiro/apply_const.hpp>
#include <mizuiro/array.hpp>
#include <mizuiro/raw_pointer.hpp>
#include <mizuiro/color/channel_proxy.hpp>
#include <mizuiro/color/is_heterogenous.hpp>
#include <mizuiro/color/detail/bit_channel_access.hpp>
#include <mizuiro/color/detail/byte_count_from_bits.hpp>
#include <mizuiro/color/detail/heterogenous_channel_bits.hpp>
#include <mizuiro/color/types/channel_reference.hpp>
#include <mizuiro/color/types/channel_value.hpp>
#include <mizuiro/color/types/pointer.hpp>
#include <mizuiro/color/types/store.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/detail/uint_least.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace types
{

MIZUIRO_DETAIL_IGNORE_EFFCPP

template<
	typename Access,
	typename Format,
	typename Constness
>
struct pointer<
	Access,
	Format,
	Constness,
	typename boost::enable_if<
		mizuiro::color::is_heterogenous<
			Format
		>
	>::type
>
:
mizuiro::apply_const<
	mizuiro::raw_pointer,
	Constness
>
{
};

template<
	typename Access,
	typename Format,
	typename Channel,
	typename Constness
>
struct channel_reference<
	Access,
	Format,
	Channel,
	Constness,
	typename boost::enable_if<
		mizuiro::color::is_heterogenous<
			Format
		>
	>::type
>
{
	typedef mizuiro::color::channel_proxy<
		typename mizuiro::color::types::pointer<
			Access,
			Format,
			Constness
		>::type,
		typename mizuiro::color::types::channel_value<
			Format,
			Channel
		>::type,
		mizuiro::color::detail::bit_channel_access<
			Format,
			Channel
		>
	> type;
};

template<
	typename Format,
	typename Channel
>
struct channel_value<
	Format,
	Channel,
	typename boost::enable_if<
		mizuiro::color::is_heterogenous<
			Format
		>
	>::type
>
:
mizuiro::detail::uint_least<
	typename mizuiro::color::detail::heterogenous_channel_bits<
		Format,
		Channel
	>::type
>
{
};

template<
	typename Access,
	typename Format
>
struct store<
	Access,
	Format,
	typename boost::enable_if<
		mizuiro::color::is_heterogenous<
			Format
		>
	>::type
>
:
mizuiro::array<
	mizuiro::raw_value,
	mizuiro::color::detail::byte_count_from_bits<
		typename Format::channel_bits
	>::value
>
{
};

MIZUIRO_DETAIL_POP_WARNING

}
}
}

#endif
