//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERT_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERT_HPP_INCLUDED

#include <mizuiro/color/access/convert.hpp>
#include <mizuiro/color/format_argument.hpp>
#include <mizuiro/color/is_color.hpp>
#include <mizuiro/color/object_impl.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <mizuiro/detail/external_end.hpp>

namespace mizuiro
{
namespace color
{

template<
	typename DestFormat,
	typename Src
>
typename boost::enable_if<
	mizuiro::color::is_color<
		Src
	>,
	color::object<
		DestFormat
	>
>::type
convert(
	Src const &_src,
	typename color::object<
		DestFormat
	>::format_store_type const &_dest_format =
		color::format_argument<DestFormat>::get()
)
{
	return
		color::access::convert<
			typename Src::format,
			DestFormat
		>::execute(
			_src,
			_dest_format
		);
}

}
}

#endif
