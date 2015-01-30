//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERT_STATIC_SAME_TO_SAME_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERT_STATIC_SAME_TO_SAME_HPP_INCLUDED

#include <mizuiro/color/object_impl.hpp>
#include <mizuiro/color/conversion/same_to_same.hpp>
#include <mizuiro/color/format/same_spaces.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <type_traits>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace convert_static
{

template<
	typename Dest,
	typename Src
>
typename
std::enable_if<
	mizuiro::color::format::same_spaces<
		Dest,
		typename
		Src::format
	>::value,
	mizuiro::color::object<
		Dest
	>
>::type
convert(
	Src const &_src
)
{
	return
		mizuiro::color::conversion::same_to_same<
			Dest
		>(
			_src
		);
}

}
}
}

#endif
