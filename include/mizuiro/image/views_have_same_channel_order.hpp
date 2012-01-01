//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_VIEWS_HAVE_SAME_CHANNEL_ORDER_HPP_INCLUDED
#define MIZUIRO_IMAGE_VIEWS_HAVE_SAME_CHANNEL_ORDER_HPP_INCLUDED

#include <mizuiro/detail/external_begin.hpp>
#include <boost/type_traits/is_same.hpp>
#include <mizuiro/detail/external_end.hpp>

namespace mizuiro
{
namespace image
{

template<
	typename View1,
	typename View2
>
struct views_have_same_channel_order
:
boost::is_same<
	typename View1::format::color_format::layout::order,
	typename View2::format::color_format::layout::order
>
{};

}
}

#endif
