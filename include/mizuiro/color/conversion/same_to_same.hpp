//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERSION_SAME_TO_SAME_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERSION_SAME_TO_SAME_HPP_INCLUDED

#include <mizuiro/color/object_impl.hpp>
#include <mizuiro/color/conversion/detail/convert_channel_function.hpp>
#include <mizuiro/color/conversion/detail/convert_each.hpp>
#include <mizuiro/color/format/argument.hpp>


namespace mizuiro
{
namespace color
{
namespace conversion
{

template<
	typename Dest,
	typename Src
>
inline
mizuiro::color::object<
	Dest
>
same_to_same(
	Src const &_src,
	typename
	mizuiro::color::object<
		Dest
	>::format_store_type const &_format
		= mizuiro::color::format::argument<
			Dest
		>::get()
)
{
	return
		mizuiro::color::conversion::detail::convert_each<
			Dest
		>(
			_src,
			mizuiro::color::conversion::detail::convert_channel_function(),
			_format
		);
}

}
}
}

#endif
