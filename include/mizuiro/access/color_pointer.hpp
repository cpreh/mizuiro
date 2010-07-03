//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_ACCESS_COLOR_POINTER_HPP_INCLUDED
#define MIZUIRO_ACCESS_COLOR_POINTER_HPP_INCLUDED

#include <mizuiro/color/types/pointer.hpp>
#include <mizuiro/image/types/pointer.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/utility/enable_if.hpp>

namespace mizuiro
{
namespace access
{

template<
	typename Access,
	typename Format,
	typename Constness
>
typename boost::enable_if<
	boost::is_same<
		typename color::types::pointer<
			Access,
			typename Format::color_format,
			Constness
		>::type,
		typename image::types::pointer<
			Access,
			Format,
			Constness
		>::type
	>,
	typename color::types::pointer<
		Access,
		typename Format::color_format,
		Constness
	>::type
>::type
color_pointer(
	Access const &,
	Format const &,
	Constness const &,
	typename image::types::pointer<
		Access,
		Format,
		Constness
	>::type const pointer
)
{
	return pointer;
}

}
}

#endif
