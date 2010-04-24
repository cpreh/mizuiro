#ifndef MIZUIRO_IS_RAW_POINTER_HPP_INCLUDED
#define MIZUIRO_IS_RAW_POINTER_HPP_INCLUDED

#include <mizuiro/raw_value.hpp>
#include <boost/mpl/and.hpp>
#include <boost/type_traits/is_pointer.hpp>
#include <boost/type_traits/remove_pointer.hpp>
#include <boost/type_traits/remove_const.hpp>

namespace mizuiro
{

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
