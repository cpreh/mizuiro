//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_MPL_TUPLE_NS_TAIL_HPP_INCLUDED
#define MIZUIRO_MPL_TUPLE_NS_TAIL_HPP_INCLUDED

#include <mizuiro/mpl/tail_ns/tag.hpp>
#include <mizuiro/mpl/tuple_ns/tag.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <tuple>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace mpl
{
namespace tail_ns
{

template<
	typename Head,
	typename... Tail
>
std::tuple<
	Tail...
>
tail_adl(
	mizuiro::mpl::tail_ns::tag,
	mizuiro::mpl::tuple_ns::tag<
		std::tuple<
			Head,
			Tail...
		>
	>
);

}
}
}

#endif
