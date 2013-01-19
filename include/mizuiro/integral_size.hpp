//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_INTEGRAL_SIZE_HPP_INCLUDED
#define MIZUIRO_INTEGRAL_SIZE_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/mpl/integral_c.hpp>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{

MIZUIRO_DETAIL_IGNORE_EFFCPP

template<
	mizuiro::size_type Size
>
struct integral_size
:
boost::mpl::integral_c<
	mizuiro::size_type,
	Size
>
{
};

MIZUIRO_DETAIL_POP_WARNING

}

#endif
