#ifndef MIZUIRO_ARRAY_HPP_INCLUDED
#define MIZUIRO_ARRAY_HPP_INCLUDED

#include <mizuiro/config.hpp>
#ifdef MIZUIRO_HAVE_FCPPT
#include <fcppt/container/array.hpp>
#include <fcppt/container/array_fusion.hpp>
#else
#include <boost/fusion/adapted/boost_array.hpp>
#include <boost/array.hpp>
#endif
#include <cstddef>

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
