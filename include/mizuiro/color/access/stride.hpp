//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_ACCESS_STRIDE_HPP_INCLUDED
#define MIZUIRO_COLOR_ACCESS_STRIDE_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <mizuiro/color/access/stride_ns/tag.hpp>
#include <mizuiro/color/format/make_tag_of.hpp>
#include <mizuiro/color/format/store_fwd.hpp>


namespace mizuiro
{
namespace color
{
namespace access
{

template<
	typename Access,
	typename Format
>
mizuiro::size_type
stride(
	mizuiro::color::format::store<
		Format
	> const &_format_store
)
{
	return
		stride_adl(
			mizuiro::color::access::stride_ns::tag(),
			Access(),
			mizuiro::color::format::make_tag_of<
				Format
			>(),
			_format_store
		);
}

}
}
}

#endif
