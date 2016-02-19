//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERSION_DETAIL_SRGB_GAMMA_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERSION_DETAIL_SRGB_GAMMA_HPP_INCLUDED

#include <mizuiro/detail/external_begin.hpp>
#include <type_traits>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace conversion
{
namespace detail
{

template<
	typename Type
>
inline
Type
srgb_gamma()
{
	static_assert(
		std::is_floating_point<
			Type
		>::value,
		"Type must be a floating point type"
	);

	return
		static_cast<
			Type
		>(
			0.45455
		);
}

}
}
}
}

#endif
