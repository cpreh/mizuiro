//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IS_RAW_POINTER_HPP_INCLUDED
#define MIZUIRO_IS_RAW_POINTER_HPP_INCLUDED

#include <mizuiro/raw_value.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/mpl/and.hpp>
#include <type_traits>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{

MIZUIRO_DETAIL_IGNORE_EFFCPP

/**
\brief A meta function that checks if T is mizuiro::raw_pointer or
mizuiro::const_raw_pointer

Checks if \a T is either mizuiro::raw_pointer or mizuiro::const_raw_pointer.

TODO: Use <type_traits> here?
*/
template<
	typename T
>
struct is_raw_pointer
:
boost::mpl::and_<
	std::is_pointer<
		T
	>,
	std::is_same<
		raw_value,
		typename std::remove_const<
			typename std::remove_pointer<
				T
			>::type
		>::type
	>
>
{};

MIZUIRO_DETAIL_POP_WARNING

}

#endif
