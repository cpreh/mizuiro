//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_OPERATORS_SCALAR_MULTIPLY_HPP_INCLUDED
#define MIZUIRO_COLOR_OPERATORS_SCALAR_MULTIPLY_HPP_INCLUDED

#include <mizuiro/decltype.hpp>
#include <mizuiro/color/for_each_channel.hpp>
#include <mizuiro/color/is_color.hpp>
#include <mizuiro/color/object_impl.hpp>
#include <mizuiro/color/format/get.hpp>
#include <mizuiro/color/types/channel_value.hpp>


namespace mizuiro
{
namespace color
{

template<
	typename Color,
	typename Scalar
>
mizuiro::color::object<
	mizuiro::color::format::get<
		Color
	>
>
operator*(
	Color const &_color,
	Scalar const _scalar
)
{
	static_assert(
		mizuiro::color::is_color<
			Color
		>::value,
		"Color must be a color type"
	);

	using
	result_type
	=
	mizuiro::color::object<
		mizuiro::color::format::get<
			Color
		>
	>;

	result_type result(
		_color
	);

	mizuiro::color::for_each_channel(
		_color,
		[
			&result,
			&_color,
			_scalar
		](
			auto const &_channel_inner
		)
		{
			result.set(
				_channel_inner,
				static_cast<
					mizuiro::color::types::channel_value<
						mizuiro::color::format::get<
							Color
						>,
						MIZUIRO_DECLTYPE(
							_channel_inner
						)
					>
				>(
					static_cast<
						Scalar
					>(
						_color.get(
							_channel_inner
						)
					)
					*
					_scalar
				)
			);
		}
	);

	return
		result;
}

template<
	typename Color,
	typename Scalar
>
mizuiro::color::object<
	mizuiro::color::format::get<
		Color
	>
>
operator*(
	Scalar const _scalar,
	Color const &_color
)
{
	static_assert(
		mizuiro::color::is_color<
			Color
		>::value,
		"Color must be a color type"
	);

	return
		_color * _scalar;
}

}
}

#endif
