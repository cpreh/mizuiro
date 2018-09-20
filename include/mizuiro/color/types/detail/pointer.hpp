//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_TYPES_DETAIL_POINTER_HPP_INCLUDED
#define MIZUIRO_COLOR_TYPES_DETAIL_POINTER_HPP_INCLUDED

#include <mizuiro/color/format/make_tag_of.hpp>
#include <mizuiro/color/types/pointer_ns/tag.hpp>
#include <mizuiro/detail/assert_access.hpp>
#include <mizuiro/detail/assert_constness.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace types
{
namespace detail
{

template<
	typename Access,
	typename Format,
	typename Constness
>
struct pointer
{
	MIZUIRO_DETAIL_ASSERT_ACCESS(
		Access
	);

	MIZUIRO_DETAIL_ASSERT_CONSTNESS(
		Constness
	);

	typedef
	decltype(
		pointer_adl(
			std::declval<
				mizuiro::color::types::pointer_ns::tag
			>(),
			std::declval<
				Access
			>(),
			mizuiro::color::format::make_tag_of<
				Format
			>(),
			std::declval<
				Constness
			>()
		)
	)
	type;
};

}
}
}
}

#endif
