//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_CONST_VIEW_HPP_INCLUDED
#define MIZUIRO_IMAGE_CONST_VIEW_HPP_INCLUDED

#include <mizuiro/const_tag.hpp>

namespace mizuiro
{
namespace image
{

template<
	typename T
>
struct const_view;

template<
	template<
		typename,
		typename,
		typename
	> class Outer,
	typename Access,
	typename Format,
	typename Constness
>
struct const_view<
	Outer<
		Access,
		Format,
		Constness
	>
>
{
	typedef Outer<
		Access,
		Format,
		mizuiro::const_tag
	> type;
};

}
}

#endif
