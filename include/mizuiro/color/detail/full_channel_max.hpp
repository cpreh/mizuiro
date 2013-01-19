//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_DETAIL_FULL_CHANNEL_MAX_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_FULL_CHANNEL_MAX_HPP_INCLUDED

#include <mizuiro/detail/external_begin.hpp>
#include <boost/type_traits/is_floating_point.hpp>
#include <boost/type_traits/is_integral.hpp>
#include <boost/utility/enable_if.hpp>
#include <limits>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace detail
{

template<
	typename Type
>
typename boost::enable_if<
	boost::is_integral<
		Type
	>,
	Type
>::type
full_channel_max()
{
	return
		std::numeric_limits<
			Type
		>::max();
}

template<
	typename Type
>
typename boost::enable_if<
	boost::is_floating_point<
		Type
	>,
	Type
>::type
full_channel_max()
{
	return
		static_cast<
			Type
		>(
			1.0
		);
}

}
}
}

#endif
