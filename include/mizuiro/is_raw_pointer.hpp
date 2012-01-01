//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IS_RAW_POINTER_HPP_INCLUDED
#define MIZUIRO_IS_RAW_POINTER_HPP_INCLUDED

#include <mizuiro/raw_value.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/mpl/and.hpp>
#include <boost/type_traits/is_pointer.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/remove_pointer.hpp>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{

/// A meta function that checks if T is raw_pointer or const_raw_pointer
template<
	typename T
>
struct is_raw_pointer
:
boost::mpl::and_<
	boost::is_pointer<
		T
	>,
	boost::is_same<
		raw_value,
		typename boost::remove_const<
			typename boost::remove_pointer<
				T
			>::type
		>::type
	>
>
{};

}

#endif
