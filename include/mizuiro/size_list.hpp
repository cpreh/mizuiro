//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_SIZE_LIST_HPP_INCLUDED
#define MIZUIRO_SIZE_LIST_HPP_INCLUDED

#include <mizuiro/integral_size.hpp>
#include <mizuiro/size_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/sequences/list.hpp>
#include <fcppt/config/external_end.hpp>


namespace mizuiro
{

template<
	mizuiro::size_type... Sizes
>
using
size_list
=
brigand::list<
	mizuiro::integral_size<
		Sizes
	>...
>;

}

#endif
