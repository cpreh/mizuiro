//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_MPL_INTEGRAL_SIZE_HPP_INCLUDED
#define MIZUIRO_MPL_INTEGRAL_SIZE_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <type_traits>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace mpl
{

/**
\brief An integral constant size of mizuiro::size_type

\tparam Size The constant size
*/
template<
	mizuiro::size_type Size
>
using integral_size
=
std::integral_constant<
	mizuiro::size_type,
	Size
>;

}
}

#endif
