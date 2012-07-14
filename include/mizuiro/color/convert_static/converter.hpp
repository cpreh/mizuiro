//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERT_STATIC_CONVERTER_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERT_STATIC_CONVERTER_HPP_INCLUDED

#include <mizuiro/color/convert_static.hpp>
#include <mizuiro/color/format_store.hpp>
#include <mizuiro/color/is_homogenous_static.hpp>
#include <mizuiro/color/object_fwd.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/mpl/and.hpp>
#include <boost/utility/enable_if.hpp>
#include <mizuiro/detail/external_end.hpp>


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
	typename boost::enable_if<
		boost::mpl::and_<
			mizuiro::color::is_homogenous_static<
				typename Source::format
			>,
			mizuiro::color::is_homogenous_static<
				DestFormat
			>
		>,
		mizuiro::color::object<
			DestFormat
		>
	>::type const
	execute(
		Source const &_source,
		mizuiro::color::format_store<
			DestFormat
		> const &
	)
	{
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
