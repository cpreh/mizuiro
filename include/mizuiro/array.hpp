//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_ARRAY_HPP_INCLUDED
#define MIZUIRO_ARRAY_HPP_INCLUDED

#include <mizuiro/detail/external_begin.hpp>
#include <boost/array.hpp>
#include <boost/fusion/adapted/boost_array.hpp>
#include <cstddef>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{

template<
	typename T,
	std::size_t N
>
using
array
=
boost::array<
	T,
	N
>;

}

#endif
