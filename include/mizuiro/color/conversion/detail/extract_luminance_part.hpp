//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERSION_DETAIL_EXTRACT_LUMINANCE_PART_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERSION_DETAIL_EXTRACT_LUMINANCE_PART_HPP_INCLUDED

#include <mizuiro/color/normalize.hpp>
#include <mizuiro/color/access/has_channel.hpp>
#include <mizuiro/color/types/has_channel_static.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
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
	typename Channel,
	typename Float,
	typename Src
>
typename boost::enable_if<
	mizuiro::color::types::has_channel_static<
		typename Src::format,
		Channel
	>,
	Float
>::type
extract_luminance_part(
	Src const &_src
)
{
	return
		mizuiro::color::access::has_channel<
			typename Src::format
		>::execute(
			_src.format_store(),
			Channel()
		)
		?
			mizuiro::color::normalize<
				Float
			>(
				_src,
				Channel()
			)
		:
			static_cast<
				Float
			>(
				0
			);
}

template<
	typename Channel,
	typename Float,
	typename Src
>
typename boost::disable_if<
	mizuiro::color::types::has_channel_static<
		typename Src::format,
		Channel
	>,
	Float
>::type
extract_luminance_part(
	Src const &
)
{
	return
		static_cast<
			Float
		>(
			0
		);
}

}
}
}
}

#endif
