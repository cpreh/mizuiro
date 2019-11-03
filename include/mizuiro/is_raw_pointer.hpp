//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IS_RAW_POINTER_HPP_INCLUDED
#define MIZUIRO_IS_RAW_POINTER_HPP_INCLUDED

#include <mizuiro/raw_value.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace mizuiro
{

/**
\brief A meta function that checks if T is mizuiro::raw_pointer or
mizuiro::const_raw_pointer

Checks if \a T is either mizuiro::raw_pointer or mizuiro::const_raw_pointer.
*/
template<
	typename T
>
using is_raw_pointer
=
std::conjunction<
	std::is_pointer<
		T
	>,
	std::is_same<
		raw_value,
		std::remove_const_t<
			std::remove_pointer_t<
				T
			>
		>
	>
>;

}

#endif
