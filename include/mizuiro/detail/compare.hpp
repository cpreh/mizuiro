//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_COMPARE_HPP_INCLUDED
#define MIZUIRO_DETAIL_COMPARE_HPP_INCLUDED

#include <mizuiro/detail/external_begin.hpp>
#include <boost/type_traits/is_floating_point.hpp>
#include <boost/utility/enable_if.hpp>
#include <limits>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace detail
{

template<
	typename T
>
inline
typename boost::disable_if<
	boost::is_floating_point<
		T
	>,
	bool
>::type
compare(
	T const &_a,
	T const &_b
)
{
	return _a == _b;
}

template<
	typename T
>
inline
typename boost::enable_if<
	boost::is_floating_point<
		T
	>,
	bool
>::type
compare(
	T const &_a,
	T const &_b
)
{
	return
		(_a - _b)
		<
		std::numeric_limits<
			T
		>::epsilon();
}

}
}

#endif
