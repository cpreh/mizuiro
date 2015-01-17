//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_RANGE_ARRAY_NS_MAKE_HPP_INCLUDED
#define MIZUIRO_RANGE_ARRAY_NS_MAKE_HPP_INCLUDED

#include <mizuiro/range/array_ns/tag.hpp>
#include <mizuiro/range/detail/array.hpp>
#include <mizuiro/range/make_ns/tag.hpp>


namespace mizuiro
{
namespace range
{
namespace array_ns
{

template<
	typename Array
>
mizuiro::range::detail::array<
	Array
>
make_adl(
	mizuiro::range::make_ns::tag,
	mizuiro::range::array_ns::tag<
		Array
	>,
	Array const &_array
)
{
	return
		mizuiro::range::detail::array<
			Array
		>(
			_array
		);
}

}
}
}

#endif
