//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_VIEWS_ARE_COMPATIBLE_HPP_INCLUDED
#define MIZUIRO_IMAGE_VIEWS_ARE_COMPATIBLE_HPP_INCLUDED

#include <mizuiro/color/format/compatible.hpp>
#include <mizuiro/mpl/bool.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <type_traits>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace image
{

/**
\brief Tests whether two views are statically compatible

Two views are statically compatible iff they are of the same dimension and
their color formats are statically compatible.
*/
template<
	typename View1,
	typename View2
>
using views_are_compatible
=
mizuiro::mpl::bool_<
	std::is_same<
		typename View1::dim,
		typename View2::dim
	>::value
	&&
	mizuiro::color::format::compatible<
// TODO: Don't use color formats here
		typename View1::format::color_format,
		typename View2::format::color_format
	>::value
>;

}
}

#endif
