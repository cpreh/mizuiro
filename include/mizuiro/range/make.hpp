//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_RANGE_MAKE_HPP_INCLUDED
#define MIZUIRO_RANGE_MAKE_HPP_INCLUDED

#include <mizuiro/range/make_tag_of.hpp>
#include <mizuiro/range/make_ns/tag.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <type_traits>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace range
{

template<
	typename Sequence
>
decltype(
	make_adl(
		mizuiro::range::make_ns::tag(),
		mizuiro::range::make_tag_of<
			Sequence
		>(),
		std::declval<
			Sequence
		>()
	)
)
make(
	Sequence const &_sequence
)
{
	return
		make_adl(
			mizuiro::range::make_ns::tag(),
			mizuiro::range::make_tag_of<
				Sequence
			>(),
			_sequence
		);
}

}
}

#endif
