//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_TYPES_HOMOGENOUS_NORMAL_HPP_INCLUDED
#define MIZUIRO_COLOR_TYPES_HOMOGENOUS_NORMAL_HPP_INCLUDED

#include <mizuiro/array.hpp>
#include <mizuiro/access/normal.hpp>
#include <mizuiro/color/is_homogenous.hpp>
#include <mizuiro/color/types/channel_reference.hpp>
#include <mizuiro/color/types/pointer.hpp>
#include <mizuiro/color/types/store.hpp>
#include <mizuiro/detail/apply_const.hpp>
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
	::mizuiro::access::normal,
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
	typename Format::channel_type *,
	Constness
>
{};

template<
	typename Format,
	typename Channel,
	typename Constness
>
struct channel_reference<
	::mizuiro::access::normal,
	Format,
	Channel,
	Constness,
	typename boost::enable_if<
		color::is_homogenous<
			Format
		>
	>::type
>
:
mizuiro::detail::apply_const<
	typename Format::channel_type &,
	Constness
>
{};

template<
	typename Format
>
struct store<
	::mizuiro::access::normal,
	Format,
	typename boost::enable_if<
		color::is_homogenous<
			Format
		>
	>::type
>
:
mizuiro::array<
	typename Format::channel_type,
	Format::element_count
>
{};

}
}
}

#endif
