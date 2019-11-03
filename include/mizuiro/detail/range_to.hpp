//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_RANGE_TO_HPP_INCLUDED
#define MIZUIRO_DETAIL_RANGE_TO_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal/list/take.hpp>
#include <metal/number/number.hpp>
#include <fcppt/config/external_end.hpp>


namespace mizuiro
{
namespace detail
{

template<
	typename List,
	mizuiro::size_type Size
>
using
range_to
=
metal::take<
	List,
	metal::number<
		Size
	>
>;

}
}

#endif
