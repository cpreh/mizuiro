//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_ACCESS_IS_HPP_INCLUDED
#define MIZUIRO_ACCESS_IS_HPP_INCLUDED

#include <mizuiro/access/normal_fwd.hpp>
#include <mizuiro/access/raw_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace mizuiro
{
namespace access
{

template<
	typename T
>
struct is
:
std::false_type
{
};

template<>
struct is<
	mizuiro::access::normal
>
:
std::true_type
{
};

template<>
struct is<
	mizuiro::access::raw
>
:
std::true_type
{
};

}
}

#endif
