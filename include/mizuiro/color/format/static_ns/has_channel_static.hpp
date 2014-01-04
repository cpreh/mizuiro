//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_STATIC_NS_HAS_CHANNEL_STATIC_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_STATIC_NS_HAS_CHANNEL_STATIC_HPP_INCLUDED

#include <mizuiro/color/format/static_ns/tag.hpp>
#include <mizuiro/color/types/has_channel_static_ns/tag.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/mpl/contains.hpp>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace types
{
namespace has_channel_static_ns
{

template<
	typename Format,
	typename Channel
>
typename
boost::mpl::contains<
	typename Format::layout::order,
	Channel
>::type
has_channel_static_adl(
	mizuiro::color::types::has_channel_static_ns::tag,
	mizuiro::color::format::static_ns::tag<
		Format
	>,
	Channel
);

}
}
}
}

#endif
