//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERT_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERT_HPP_INCLUDED

#include <mizuiro/color/is_color.hpp>
#include <mizuiro/color/object_impl.hpp>
#include <mizuiro/color/format/argument.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace color
{

template<
	typename Converter,
	typename DestFormat,
	typename Src
>
typename
boost::enable_if<
	mizuiro::color::is_color<
		Src
	>,
	mizuiro::color::object<
		DestFormat
	>
>::type
convert(
	Src const &_src,
	typename
	mizuiro::color::object<
		DestFormat
	>::format_store_type const &_dest_format =
		mizuiro::color::format::argument<
			DestFormat
		>::get()
)
{
	return
		Converter:: template execute<
			DestFormat
		>(
			_src,
			_dest_format
		);
}

}
}

#endif
