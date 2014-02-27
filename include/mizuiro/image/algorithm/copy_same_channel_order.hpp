//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_COPY_SAME_CHANNEL_ORDER_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_COPY_SAME_CHANNEL_ORDER_HPP_INCLUDED

#include <mizuiro/detail/copy.hpp>
#include <mizuiro/detail/copy_overlap.hpp>
#include <mizuiro/image/linear_view_fwd.hpp>
#include <mizuiro/image/algorithm/binary_iteration.hpp>
#include <mizuiro/image/algorithm/may_overlap.hpp>
#include <mizuiro/image/algorithm/detail/copy_element.hpp>


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
	ViewD const &_dest,
	mizuiro::image::algorithm::may_overlap
)
{
	mizuiro::image::algorithm::binary_iteration(
		mizuiro::image::algorithm::detail::copy_element(),
		_src,
		_dest
	);
}

template<
	typename Access1,
	typename Format1,
	typename Constness1,
	typename Access2,
	typename Format2,
	typename Constness2
>
void
copy_same_channel_order(
	mizuiro::image::linear_view<
		Access1,
		Format1,
		Constness1
	> const &_src,
	mizuiro::image::linear_view<
		Access2,
		Format2,
		Constness2
	> const &_dest,
	mizuiro::image::algorithm::may_overlap const _overlap
)
{
	if(
		_overlap
		==
		mizuiro::image::algorithm::may_overlap::yes
	)
		mizuiro::detail::copy_overlap(
			_src.begin().data(),
			_src.end().data(),
			_dest.begin().data()
		);
	else
		mizuiro::detail::copy(
			_src.begin().data(),
			_src.end().data(),
			_dest.begin().data()
		);
}

}
}
}

#endif
