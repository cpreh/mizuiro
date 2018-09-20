//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_INT_TO_TRUE_HPP_INCLUDED
#define MIZUIRO_DETAIL_INT_TO_TRUE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace mizuiro
{
namespace detail
{

template<
	int
>
struct int_to_true
:
std::true_type
{
};

}
}

#endif
