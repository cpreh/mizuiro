//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_MPL_MAKE_TAG_OF_HPP_INCLUDED
#define MIZUIRO_MPL_MAKE_TAG_OF_HPP_INCLUDED

#include <mizuiro/mpl/tag_of_fwd.hpp>


namespace mizuiro
{
namespace mpl
{

template<
	typename Type
>
typename
mizuiro::mpl::tag_of<
	Type
>::type
make_tag_of()
{
	return
		typename
		mizuiro::mpl::tag_of<
			Type
		>::type();
}

}
}

#endif
