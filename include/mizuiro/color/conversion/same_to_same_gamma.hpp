//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERSION_SAME_TO_SAME_GAMMA_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERSION_SAME_TO_SAME_GAMMA_HPP_INCLUDED

#include <mizuiro/decltype.hpp>
#include <mizuiro/color/object_impl.hpp>
#include <mizuiro/color/conversion/detail/convert_each.hpp>
#include <mizuiro/color/format/get.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cmath>
#include <fcppt/config/external_end.hpp>


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
			[
				_gamma
			](
				auto const &_channel_inner,
				auto const &_src_inner,
				auto &_dest_inner
			)
			{
				_dest_inner.set(
					_channel_inner,
					mizuiro::color::denormalize<
						mizuiro::color::format::get<
							MIZUIRO_DECLTYPE(
								_dest_inner
							)
						>
					>(
						_dest_inner.format_store(),
						_channel_inner,
						std::pow(
							mizuiro::color::normalize<
								// TODO!
								float
							>(
								_src_inner,
								_channel_inner
							),
							_gamma
						)
					)
				);
			},
			_format
		);
}

}
}
}

#endif
