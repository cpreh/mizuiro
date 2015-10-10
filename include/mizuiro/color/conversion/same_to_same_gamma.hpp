//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERSION_SAME_TO_SAME_GAMMA_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERSION_SAME_TO_SAME_GAMMA_HPP_INCLUDED

#include <mizuiro/color/object_impl.hpp>
#include <mizuiro/color/conversion/detail/convert_channel_gamma_function.hpp>
#include <mizuiro/color/conversion/detail/convert_each.hpp>


namespace mizuiro
{
namespace color
{
namespace conversion
{

template<
	typename Dest,
	typename Src,
	typename Gamma
>
inline
mizuiro::color::object<
	Dest
>
same_to_same_gamma(
	Src const &_src,
	Gamma const _gamma,
	typename
	mizuiro::color::object<
		Dest
	>::format_store_type const &_format
)
{
	return
		mizuiro::color::conversion::detail::convert_each<
			Dest
		>(
			_src,
			mizuiro::color::conversion::detail::convert_channel_gamma_function<
				Gamma
			>(
				_gamma
			),
			_format
		);
}

}
}
}

#endif
