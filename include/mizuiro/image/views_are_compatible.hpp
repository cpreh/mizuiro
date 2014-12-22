//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_VIEWS_ARE_COMPATIBLE_HPP_INCLUDED
#define MIZUIRO_IMAGE_VIEWS_ARE_COMPATIBLE_HPP_INCLUDED

#include <mizuiro/color/formats_are_compatible.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/size.hpp>
#include <type_traits>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace image
{

template<
	typename View1,
	typename View2
>
using views_are_compatible
=
boost::mpl::and_<
	std::is_same<
		typename View1::dim,
		typename View2::dim
	>,
	// TODO: Is this correct?
	boost::mpl::equal_to<
		boost::mpl::size<
			typename View1::format::color_format::layout::order
		>,
		boost::mpl::size<
			typename View2::format::color_format::layout::order
		>
	>,
	mizuiro::color::formats_are_compatible<
		typename View1::format::color_format,
		typename View2::format::color_format
	>
>;

}
}

#endif
