//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_MPL_TAIL_HPP_INCLUDED
#define MIZUIRO_MPL_TAIL_HPP_INCLUDED

#include <mizuiro/mpl/make_tag_of.hpp>
#include <mizuiro/mpl/tail_ns/tag.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace mizuiro
{
namespace mpl
{

template<
	typename Type
>
using tail
=
decltype(
	tail_adl(
		std::declval<
			mizuiro::mpl::tail_ns::tag
		>(),
		mizuiro::mpl::make_tag_of<
			Type
		>()
	)
);

}
}

#endif
