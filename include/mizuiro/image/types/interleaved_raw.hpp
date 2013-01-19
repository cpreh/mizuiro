//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_TYPES_INTERLEAVED_RAW_HPP_INCLUDED
#define MIZUIRO_IMAGE_TYPES_INTERLEAVED_RAW_HPP_INCLUDED

#include <mizuiro/raw_value.hpp>
#include <mizuiro/access/raw.hpp>
#include <mizuiro/image/is_interleaved.hpp>
#include <mizuiro/image/detail/raw_container_fwd.hpp>
#include <mizuiro/image/types/store.hpp>
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
struct store<
	::mizuiro::access::raw,
	ImageFormat,
	typename boost::enable_if<
		mizuiro::image::is_interleaved<
			ImageFormat
		>
	>::type
>
{
	typedef mizuiro::image::detail::raw_container<
		mizuiro::raw_value
	> type;
};

}
}
}

#endif
