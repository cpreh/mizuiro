//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_TYPES_INTERLEAVED_NORMAL_HPP_INCLUDED
#define MIZUIRO_IMAGE_TYPES_INTERLEAVED_NORMAL_HPP_INCLUDED

#include <mizuiro/access/normal.hpp>
#include <mizuiro/color/types/store.hpp>
#include <mizuiro/image/detail/raw_container_fwd.hpp>
#include <mizuiro/image/types/data_store.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace image
{
namespace types
{

template<
	typename ImageFormat
>
struct data_store<
	::mizuiro::access::normal,
	ImageFormat,
	typename boost::enable_if<
		::mizuiro::image::is_interleaved<
			ImageFormat
		>
	>::type
>
{
	typedef mizuiro::image::detail::raw_container<
		typename ImageFormat::color_format::channel_type
	> type;
};

}
}
}

#endif
