//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_MPL_TUPLE_NS_EMPTY_HPP_INCLUDED
#define MIZUIRO_MPL_TUPLE_NS_EMPTY_HPP_INCLUDED

#include <mizuiro/mpl/bool.hpp>
#include <mizuiro/mpl/empty_ns/tag.hpp>
#include <mizuiro/mpl/tuple_ns/tag.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <tuple>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace mpl
{
namespace empty_ns
{

template<
	typename Tuple
>
mizuiro::mpl::bool_<
	std::tuple_size<
		Tuple
	>::value
	==
	0
>
empty_adl(
	mizuiro::mpl::empty_ns::tag,
	mizuiro::mpl::tuple_ns::tag<
		Tuple
	>
);

}
}
}

#endif
