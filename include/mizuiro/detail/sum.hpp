//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_SUM_HPP_INCLUDED
#define MIZUIRO_DETAIL_SUM_HPP_INCLUDED

#include <fcppt/metal/from_number.hpp>
#include <fcppt/metal/to_number_list.hpp>
#include <mizuiro/size_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
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
fcppt::metal::from_number<
	mizuiro::size_type,
	metal::accumulate<
		metal::lambda<
			metal::add
		>,
		metal::number<
			0u
		>,
		fcppt::metal::to_number_list<
			List
		>
	>
>;

}
}

#endif
