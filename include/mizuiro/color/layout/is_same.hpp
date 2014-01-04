//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_LAYOUT_IS_SAME_HPP_INCLUDED
#define MIZUIRO_COLOR_LAYOUT_IS_SAME_HPP_INCLUDED

#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <type_traits>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace layout
{

MIZUIRO_DETAIL_IGNORE_EFFCPP

template<
	typename A,
	typename B
>
struct is_same
:
std::is_same<
	A,
	B
>
{
};

template<
	template<
		typename
	> class Outer,
	typename Inner1,
	typename Inner2
>
struct is_same<
	Outer<
		Inner1
	>,
	Outer<
		Inner2
	>
>
:
std::true_type
{
};

MIZUIRO_DETAIL_POP_WARNING

}
}
}

#endif
