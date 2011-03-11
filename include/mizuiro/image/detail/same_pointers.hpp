//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_DETAIL_SAME_POINTERS_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_SAME_POINTERS_HPP_INCLUDED

#include <mizuiro/color/types/pointer.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/remove_pointer.hpp>

namespace mizuiro
{
namespace image
{
namespace detail
{

template<
	typename View1,
	typename View2
>
struct same_pointers
:
boost::is_same<
	typename boost::remove_const<
		typename boost::remove_pointer<
			typename mizuiro::color::types::pointer<
				typename View1::access,
				typename View1::color_format,
				typename View1::constness
			>::type
		>::type
	>::type,
	typename boost::remove_const<
		typename boost::remove_pointer<
			typename mizuiro::color::types::pointer<
				typename View2::access,
				typename View2::color_format,
				typename View2::constness
			>::type
		>::type
	>::type
>
{
};

}
}
}

#endif
