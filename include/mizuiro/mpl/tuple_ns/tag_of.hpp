//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_MPL_TUPLE_NS_TAG_OF_HPP_INCLUDED
#define MIZUIRO_MPL_TUPLE_NS_TAG_OF_HPP_INCLUDED

#include <mizuiro/mpl/tag_of_fwd.hpp>
#include <mizuiro/mpl/tuple_ns/tag.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <tuple>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace mpl
{

template<
	typename... Sequence
>
struct
tag_of<
	std::tuple<
		Sequence...
	>
>
{
	typedef
	mizuiro::mpl::tuple_ns::tag<
		std::tuple<
			Sequence...
		>
	>
	type;
};

}
}

#endif
