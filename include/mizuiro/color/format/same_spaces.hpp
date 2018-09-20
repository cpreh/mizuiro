//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_SAME_SPACES_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_SAME_SPACES_HPP_INCLUDED

#include <mizuiro/color/types/space.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace format
{

template<
	typename A,
	typename B
>
using same_spaces
=
std::is_same<
	mizuiro::color::types::space<
		A
	>,
	mizuiro::color::types::space<
		B
	>
>;

}
}
}

#endif
