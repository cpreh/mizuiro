//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_COPY_DIFFERENT_CHANNEL_ORDER_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_COPY_DIFFERENT_CHANNEL_ORDER_HPP_INCLUDED

#include <mizuiro/image/algorithm/detail/apply_binary_iteration.hpp>
#include <mizuiro/image/algorithm/detail/copy_element_overlapping.hpp>
#include <mizuiro/image/algorithm/detail/copy_element.hpp>
#include <mizuiro/image/views_overlap.hpp>
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
copy_different_channel_order(
	ViewS const &_src,
	ViewD const &_dest
)
{
	if(
		image::views_overlap(
			_src,
			_dest
		)
	)
		mizuiro::detail::variant_apply_binary(
			algorithm::detail::apply_binary_iteration(
				algorithm::detail::copy_element_overlapping()
			),
			_src.range(),
			_dest.range()
		);
	else
		mizuiro::detail::variant_apply_binary(
			algorithm::detail::apply_binary_iteration(
				algorithm::detail::copy_element()
			),
			_src.range(),
			_dest.range()
		);
}

}
}
}

#endif
