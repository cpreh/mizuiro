//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_MPL_HEAD_HPP_INCLUDED
#define MIZUIRO_MPL_HEAD_HPP_INCLUDED

#include <mizuiro/mpl/make_tag_of.hpp>
#include <mizuiro/mpl/head_ns/tag.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <type_traits>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace mpl
{

template<
	typename Type
>
using head
=
decltype(
	head_adl(
		std::declval<
			mizuiro::mpl::head_ns::tag
		>(),
		mizuiro::mpl::make_tag_of<
			Type
		>()
	)
);

}
}

#endif
