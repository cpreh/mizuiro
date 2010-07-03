//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_ACCESS_IS_RAW_HPP_INCLUDED
#define MIZUIRO_ACCESS_IS_RAW_HPP_INCLUDED

#include <mizuiro/access/raw.hpp>
#include <boost/type_traits/is_same.hpp>

namespace mizuiro
{
namespace access
{

template<
	typename T
>
struct is_raw
:
boost::is_same<
	T,
	raw
>
{};

}
}

#endif
