//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_TYPES_RAW_HPP_INCLUDED
#define MIZUIRO_IMAGE_TYPES_RAW_HPP_INCLUDED

#include <mizuiro/image/types/pointer.hpp>
#include <mizuiro/image/types/data_store.hpp>
#include <mizuiro/image/detail/raw_container_fwd.hpp>
#include <mizuiro/color/types/homogenous_raw.hpp>
#include <mizuiro/color/types/pointer.hpp>
#include <mizuiro/color/is_homogenous.hpp>
#include <mizuiro/access/raw.hpp>
#include <mizuiro/raw_value.hpp>
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
	typename Format,
	typename Constness
>
struct pointer<
	::mizuiro::access::raw,
	Format,
	Constness
>
:
color::types::pointer<
	::mizuiro::access::raw,
	typename Format::color_format,
	Constness
>
{
};

template<
	typename Format
>
struct data_store<
	::mizuiro::access::raw,
	Format,
	typename boost::enable_if<
		::mizuiro::color::is_homogenous<
			Format
		>
	>::type
>
{
	typedef detail::raw_container<
		mizuiro::raw_value
	> type;
};

}
}
}

#endif
