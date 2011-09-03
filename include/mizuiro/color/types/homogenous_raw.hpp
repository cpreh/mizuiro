//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_TYPES_HOMOGENOUS_RAW_HPP_INCLUDED
#define MIZUIRO_COLOR_TYPES_HOMOGENOUS_RAW_HPP_INCLUDED

#include <mizuiro/color/types/pointer.hpp>
#include <mizuiro/color/types/channel_reference.hpp>
#include <mizuiro/color/types/store.hpp>
#include <mizuiro/color/types/homogenous.hpp>
#include <mizuiro/color/types/channel_value.hpp>
#include <mizuiro/color/channel_proxy_impl.hpp>
#include <mizuiro/color/is_homogenous.hpp>
#include <mizuiro/access/raw.hpp>
#include <mizuiro/detail/apply_const.hpp>
#include <mizuiro/array.hpp>
#include <mizuiro/raw_value.hpp>
#include <mizuiro/raw_pointer.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <mizuiro/detail/external_end.hpp>

namespace mizuiro
{
namespace color
{
namespace types
{

template<
	typename Format,
	typename Constness
>
struct pointer<
	::mizuiro::access::raw,
	Format,
	Constness,
	typename boost::enable_if<
		color::is_homogenous<
			Format
		>
	>::type
>
:
mizuiro::detail::apply_const<
	mizuiro::raw_pointer,
	Constness
>
{
};

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
		color::is_homogenous<
			Format
		>
	>::type
>
{
	typedef color::channel_proxy<
		typename types::pointer<
			::mizuiro::access::raw,
			Format,
			Constness
		>::type,
		typename types::channel_value<
			Format,
			Channel
		>::type
	> type;
};

template<
	typename Format
>
struct store<
	::mizuiro::access::raw,
	Format,
	typename boost::enable_if<
		color::is_homogenous<
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
{};

}
}
}

#endif
