//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_COPY_SAME_CHANNEL_ORDER_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_COPY_SAME_CHANNEL_ORDER_HPP_INCLUDED

#include <mizuiro/image/algorithm/detail/copy_raw.hpp>
#include <mizuiro/detail/variant_apply_binary.hpp>

namespace mizuiro
{
namespace image
{
namespace algorithm
{

template<
	typename ViewS,
	typename ViewD
>
void
copy_same_channel_order(
	ViewS const &_src,
	ViewD const &_dest
)
{
	mizuiro::detail::variant_apply_binary(
		detail::copy_raw(),
		_src.range(),
		_dest.range()
	);
}

}
}
}

#endif
