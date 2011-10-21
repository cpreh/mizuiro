//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_COPY_DIFFERENT_CHANNEL_ORDER_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_COPY_DIFFERENT_CHANNEL_ORDER_HPP_INCLUDED

#include <mizuiro/image/algorithm/binary_iteration.hpp>
#include <mizuiro/image/algorithm/may_overlap.hpp>
#include <mizuiro/image/algorithm/detail/copy_element.hpp>
#include <mizuiro/image/algorithm/detail/copy_element_overlapping.hpp>


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
copy_different_channel_order(
	ViewS const &_src,
	ViewD const &_dest,
	algorithm::may_overlap::type const _overlap
)
{
	if(
		_overlap
		== algorithm::may_overlap::yes
	)
		algorithm::binary_iteration(
			algorithm::detail::copy_element_overlapping(),
			_src,
			_dest
		);
	else
		algorithm::binary_iteration(
			algorithm::detail::copy_element(),
			_src,
			_dest
		);
}

}
}
}

#endif
