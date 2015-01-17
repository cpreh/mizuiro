//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_INT_TO_TRUE_HPP_INCLUDED
#define MIZUIRO_DETAIL_INT_TO_TRUE_HPP_INCLUDED

#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/mpl/true.hpp>


namespace mizuiro
{
namespace detail
{

MIZUIRO_DETAIL_IGNORE_EFFCPP

template<
	int
>
struct int_to_true
:
mizuiro::mpl::true_
{
};

MIZUIRO_DETAIL_POP_WARNING

}
}

#endif
