//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_SUM_HPP_INCLUDED
#define MIZUIRO_DETAIL_SUM_HPP_INCLUDED

#include <mizuiro/integral_size.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/algorithms/fold.hpp>
#include <brigand/functions/arithmetic/plus.hpp>
#include <brigand/types/args.hpp>
#include <fcppt/config/external_end.hpp>


namespace mizuiro
{
namespace detail
{

template<
	typename List
>
using
sum
=
brigand::fold<
	List,
	mizuiro::integral_size<
		0u
	>,
	brigand::plus<
		brigand::_1,
		brigand::_2
	>
>;

}
}

#endif
