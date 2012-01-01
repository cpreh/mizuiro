//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_DETAIL_RAW_CONTAINER_FWD_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_RAW_CONTAINER_FWD_HPP_INCLUDED

#include <mizuiro/detail/external_begin.hpp>
#include <memory>
#include <mizuiro/detail/external_end.hpp>

namespace mizuiro
{
namespace image
{
namespace detail
{

template<
	typename T,
	typename A = std::allocator<T>
>
class raw_container;

}
}
}

#endif
