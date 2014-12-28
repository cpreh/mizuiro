//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_HETEROGENOUS_NS_STORE_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_HETEROGENOUS_NS_STORE_HPP_INCLUDED

#include <mizuiro/array.hpp>
#include <mizuiro/color/detail/heterogenous_bits.hpp>
#include <mizuiro/color/format/heterogenous_ns/tag.hpp>
#include <mizuiro/color/types/store_ns/tag.hpp>
#include <mizuiro/detail/uint_least.hpp>


namespace mizuiro
{
namespace color
{
namespace types
{
namespace store_ns
{

template<
	typename Format
>
// TODO: Make it possible to use something else here which doesn't require .data()
mizuiro::array<
	// TODO: Also refactor this to use channel_value
	mizuiro::detail::uint_least<
		typename
		mizuiro::color::detail::heterogenous_bits<
			typename
			Format::channel_bits
		>::type
	>,
	1u
>
store_adl(
	mizuiro::color::types::store_ns::tag,
	mizuiro::color::format::heterogenous_ns::tag<
		Format
	>
);

}
}
}
}

#endif
