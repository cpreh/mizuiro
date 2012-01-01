//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_STORE_FWD_HPP_INCLUDED
#define MIZUIRO_IMAGE_STORE_FWD_HPP_INCLUDED

#include <mizuiro/access/normal.hpp>

namespace mizuiro
{
namespace image
{

template<
	typename Format,
	typename Access
		= ::mizuiro::access::normal
>
class store;

}
}

#endif
