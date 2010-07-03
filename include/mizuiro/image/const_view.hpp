//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_CONST_VIEW_HPP_INCLUDED
#define MIZUIRO_IMAGE_CONST_VIEW_HPP_INCLUDED

#include <mizuiro/image/view_fwd.hpp>
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
	typename Access,
	typename Format,
	typename Constness
>
struct const_view<
	view<
		Access,
		Format,
		Constness
	>
>
{
	typedef view<
		Access,
		Format,
		mizuiro::const_tag
	> type;
};

}
}

#endif
