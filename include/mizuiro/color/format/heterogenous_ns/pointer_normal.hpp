//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_HETEROGENOUS_NS_POINTER_NORMAL_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_HETEROGENOUS_NS_POINTER_NORMAL_HPP_INCLUDED

#include <mizuiro/apply_const_result.hpp>
#include <mizuiro/access/normal.hpp>
#include <mizuiro/color/detail/heterogenous_bits.hpp>
#include <mizuiro/color/format/heterogenous_ns/tag.hpp>
#include <mizuiro/color/types/pointer_ns/tag.hpp>
#include <mizuiro/detail/uint_least.hpp>


namespace mizuiro
{
namespace color
{
namespace types
{
namespace pointer_ns
{

template<
	typename Format,
	typename Constness
>
mizuiro::apply_const_result<
	// TODO: Refactor this because it is the same as channel_value
	typename
	mizuiro::detail::uint_least<
		typename
		mizuiro::color::detail::heterogenous_bits<
			typename
			Format::channel_bits
		>::type
	>::type *,
	Constness
>
pointer_adl(
	mizuiro::color::types::pointer_ns::tag,
	mizuiro::access::normal,
	mizuiro::color::format::heterogenous_ns::tag<
		Format
	>,
	Constness
);

}
}
}
}

#endif
