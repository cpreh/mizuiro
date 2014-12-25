//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_RANGE_ARRAY_NS_TAG_OF_HPP_INCLUDED
#define MIZUIRO_RANGE_ARRAY_NS_TAG_OF_HPP_INCLUDED

#include <mizuiro/array.hpp>
#include <mizuiro/range/tag_of_fwd.hpp>
#include <mizuiro/range/array_ns/tag.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <cstddef>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace range
{

template<
	typename Type,
	std::size_t Size
>
struct
tag_of<
	mizuiro::array<
		Type,
		Size
	>
>
{
	typedef
	mizuiro::range::array_ns::tag<
		mizuiro::array<
			Type,
			Size
		>
	>
	type;
};

}
}

#endif
