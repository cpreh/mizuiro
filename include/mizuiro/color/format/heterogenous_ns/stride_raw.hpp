//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_HETEROGENOUS_NS_STRIDE_RAW_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_HETEROGENOUS_NS_STRIDE_RAW_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <mizuiro/access/raw.hpp>
#include <mizuiro/color/access/stride_ns/tag.hpp>
#include <mizuiro/color/detail/heterogenous_bits.hpp>
#include <mizuiro/color/format/store_fwd.hpp>
#include <mizuiro/color/format/heterogenous_ns/tag.hpp>
#include <mizuiro/detail/byte_count_from_bits.hpp>


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
	mizuiro::access::raw const &,
	mizuiro::color::format::heterogenous_ns::tag<
		Format
	>,
	mizuiro::color::format::store<
		Format
	> const &
)
{
	return
		mizuiro::detail::byte_count_from_bits<
			typename
			mizuiro::color::detail::heterogenous_bits<
				typename
				Format::channel_bits
			>::type
		>::value;
}

}
}
}
}

#endif
