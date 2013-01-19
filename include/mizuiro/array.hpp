//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_ARRAY_HPP_INCLUDED
#define MIZUIRO_ARRAY_HPP_INCLUDED

#include <mizuiro/config.hpp>
#ifdef MIZUIRO_HAVE_FCPPT
#include <fcppt/container/array.hpp>
#include <fcppt/container/array_fusion.hpp>
#else
#include <mizuiro/detail/external_begin.hpp>
#include <boost/fusion/adapted/boost_array.hpp>
#include <boost/array.hpp>
#include <mizuiro/detail/external_end.hpp>
#endif
#include <mizuiro/detail/external_begin.hpp>
#include <cstddef>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{

/// mizuiro's array type
/**
 * Exposes a typedef ::type.
*/
template<
	typename T,
	std::size_t N
>
struct array
{
#ifdef MIZUIRO_HAVE_FCPPT
	typedef fcppt::container::array<
		T,
		N
	> type;
#else
	typedef boost::array<
		T,
		N
	> type;
#endif
};

}

#endif
