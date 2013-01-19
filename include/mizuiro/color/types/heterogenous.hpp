//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_TYPES_HETEROGENOUS_HPP_INCLUDED
#define MIZUIRO_COLOR_TYPES_HETEROGENOUS_HPP_INCLUDED

#include <mizuiro/color/is_heterogenous.hpp>
#include <mizuiro/color/detail/heterogenous_channel_bits.hpp>
#include <mizuiro/color/types/channel_value.hpp>
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

MIZUIRO_DETAIL_POP_WARNING

}
}
}

#endif
