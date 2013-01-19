//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_TYPES_HOMOGENOUS_RAW_HPP_INCLUDED
#define MIZUIRO_COLOR_TYPES_HOMOGENOUS_RAW_HPP_INCLUDED

#include <mizuiro/apply_const.hpp>
#include <mizuiro/array.hpp>
#include <mizuiro/raw_pointer.hpp>
#include <mizuiro/raw_value.hpp>
#include <mizuiro/access/raw.hpp>
#include <mizuiro/color/channel_proxy_impl.hpp>
#include <mizuiro/color/is_homogenous.hpp>
#include <mizuiro/color/detail/raw_channel_access.hpp>
#include <mizuiro/color/types/channel_reference.hpp>
#include <mizuiro/color/types/channel_value.hpp>
#include <mizuiro/color/types/homogenous.hpp>
#include <mizuiro/color/types/pointer.hpp>
#include <mizuiro/color/types/store.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>
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
	typename Format,
	typename Constness
>
struct pointer<
	::mizuiro::access::raw,
	Format,
	Constness,
	typename boost::enable_if<
		mizuiro::color::is_homogenous<
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

MIZUIRO_DETAIL_POP_WARNING

template<
	typename Format,
	typename Channel,
	typename Constness
>
struct channel_reference<
	::mizuiro::access::raw,
	Format,
	Channel,
	Constness,
	typename boost::enable_if<
		mizuiro::color::is_homogenous<
			Format
		>
	>::type
>
{
	typedef mizuiro::color::channel_proxy<
		typename mizuiro::color::types::pointer<
			::mizuiro::access::raw,
			Format,
			Constness
		>::type,
		typename mizuiro::color::types::channel_value<
			Format,
			Channel
		>::type,
		mizuiro::color::detail::raw_channel_access<
			typename mizuiro::color::types::channel_value<
				Format,
				Channel
			>::type
		>
	> type;
};

MIZUIRO_DETAIL_IGNORE_EFFCPP

template<
	typename Format
>
struct store<
	::mizuiro::access::raw,
	Format,
	typename boost::enable_if<
		mizuiro::color::is_homogenous<
			Format
		>
	>::type
>
:
mizuiro::array<
	mizuiro::raw_value,
	Format::element_count
	* sizeof(typename Format::channel_type)
>
{
};

MIZUIRO_DETAIL_POP_WARNING

}
}
}

#endif
