//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERT_STATIC_IS_HSV_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERT_STATIC_IS_HSV_HPP_INCLUDED

#include <mizuiro/color/channel/hue.hpp>
#include <mizuiro/color/channel/saturation.hpp>
#include <mizuiro/color/channel/value.hpp>
#include <mizuiro/color/types/has_channel_static.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/mpl/and.hpp>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace convert_static
{

MIZUIRO_DETAIL_IGNORE_EFFCPP

template<
	typename Format
>
struct is_hsv
:
boost::mpl::and_<
	mizuiro::color::types::has_channel_static<
		Format,
		mizuiro::color::channel::hue
	>,
	mizuiro::color::types::has_channel_static<
		Format,
		mizuiro::color::channel::saturation
	>,
	mizuiro::color::types::has_channel_static<
		Format,
		mizuiro::color::channel::value
	>
>
{
};

MIZUIRO_DETAIL_POP_WARNING

}
}
}

#endif
