//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_HETEROGENOUS_NS_STRIDE_NORMAL_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_HETEROGENOUS_NS_STRIDE_NORMAL_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <mizuiro/access/normal.hpp>
#include <mizuiro/color/access/stride_ns/tag.hpp>
#include <mizuiro/color/format/store_fwd.hpp>
#include <mizuiro/color/format/heterogenous_ns/tag.hpp>


namespace mizuiro
{
namespace color
{
namespace access
{
namespace stride_ns
{

template<
	typename Format
>
mizuiro::size_type
stride_adl(
	mizuiro::color::access::stride_ns::tag,
	mizuiro::access::normal const &,
	mizuiro::color::format::heterogenous_ns::tag<
		Format
	>,
	mizuiro::color::format::store<
		Format
	> const &
)
{
	return
		1u;
}

}
}
}
}

#endif
