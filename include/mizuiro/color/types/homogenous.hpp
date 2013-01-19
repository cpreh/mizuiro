//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_TYPES_HOMOGENOUS_HPP_INCLUDED
#define MIZUIRO_COLOR_TYPES_HOMOGENOUS_HPP_INCLUDED

#include <mizuiro/color/is_homogenous.hpp>
#include <mizuiro/color/types/channel_value.hpp>
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
	typename Channel
>
struct channel_value<
	Format,
	Channel,
	typename boost::enable_if<
		color::is_homogenous<
			Format
		>
	>::type
>
{
	typedef typename Format::channel_type type;
};

}
}
}

#endif
