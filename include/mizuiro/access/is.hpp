//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_ACCESS_IS_HPP_INCLUDED
#define MIZUIRO_ACCESS_IS_HPP_INCLUDED

#include <mizuiro/access/normal_fwd.hpp>
#include <mizuiro/access/raw_fwd.hpp>
#include <mizuiro/mpl/false.hpp>
#include <mizuiro/mpl/true.hpp>


namespace mizuiro
{
namespace access
{

template<
	typename T
>
struct is
:
mizuiro::mpl::false_
{
};

template<>
struct is<
	mizuiro::access::normal
>
:
mizuiro::mpl::true_
{
};

template<>
struct is<
	mizuiro::access::raw
>
:
mizuiro::mpl::true_
{
};

}
}

#endif
