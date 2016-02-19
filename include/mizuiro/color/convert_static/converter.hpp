//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERT_STATIC_CONVERTER_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERT_STATIC_CONVERTER_HPP_INCLUDED

#include <mizuiro/color/convert_static.hpp>
#include <mizuiro/color/object_impl.hpp>
#include <mizuiro/color/convert_static/is_static.hpp>
#include <mizuiro/color/format/store.hpp>


namespace mizuiro
{
namespace color
{
namespace convert_static
{

struct converter
{
	template<
		typename DestFormat,
		typename Source
	>
	static
	mizuiro::color::object<
		DestFormat
	>
	execute(
		Source const &_source,
		mizuiro::color::format::store<
			DestFormat
		> const &
	)
	{
		static_assert(
			mizuiro::color::convert_static::is_static<
				typename
				Source::format
			>::value,
			"The source format must be static"
		);

		static_assert(
			mizuiro::color::convert_static::is_static<
				DestFormat
			>::value,
			"The destination format must be static"
		);

		return
			mizuiro::color::convert_static::convert<
				DestFormat
			>(
				_source
			);
	}
};

}
}
}

#endif
