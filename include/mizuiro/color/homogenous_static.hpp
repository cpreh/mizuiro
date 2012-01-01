//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_HOMOGENOUS_STATIC_HPP_INCLUDED
#define MIZUIRO_COLOR_HOMOGENOUS_STATIC_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <mizuiro/color/homogenous_static_fwd.hpp>
#include <mizuiro/color/access/homogenous_normal.hpp>
#include <mizuiro/color/access/homogenous_static.hpp>
#include <mizuiro/color/types/homogenous.hpp>
#include <mizuiro/color/types/homogenous_normal.hpp>
#include <mizuiro/color/types/homogenous_static.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/mpl/size.hpp>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace color
{

template<
	typename ChannelType,
	typename Layout
>
struct homogenous_static
{
	typedef ChannelType channel_type;

	typedef Layout layout;

	typedef typename Layout::order order;

	static size_type const element_count
		= boost::mpl::size<
			typename layout::order
		>::value;
};

}
}

#endif
