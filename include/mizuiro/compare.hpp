//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COMPARE_HPP_INCLUDED
#define MIZUIRO_COMPARE_HPP_INCLUDED

#include <mizuiro/detail/compare.hpp>

namespace mizuiro
{

/// Compares two values with a special case for floats
/**
 * For floats the function checks if they are almost the same
 * because floating point comparison with != or == is unsafe.
 * For all other types == will be used.
*/
template<
	typename T
>
inline
bool
compare(
	T const &_a,
	T const &_b
)
{
	return
		mizuiro::detail::compare(
			_a,
			_b
		);
}

}

#endif
