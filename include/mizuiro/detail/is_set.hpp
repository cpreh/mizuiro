//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_IS_SET_HPP_INCLUDED
#define MIZUIRO_DETAIL_IS_SET_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <brigand/sequences/set.hpp>
#include <brigand/sequences/size.hpp>
#include <brigand/types/bool.hpp>
#include <fcppt/config/external_end.hpp>


namespace mizuiro
{
namespace detail
{

template<
	typename List
>
using
is_set
=
brigand::bool_<
	brigand::size<
		brigand::as_set<
			List
		>
	>::value
	==
	brigand::size<
		List
	>::value
>;

}
}

#endif
