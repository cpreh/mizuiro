//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_COPY_DIFFERENT_CHANNEL_ORDER_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_COPY_DIFFERENT_CHANNEL_ORDER_HPP_INCLUDED

#include <mizuiro/image/algorithm/make_iterator_identity.hpp>
#include <mizuiro/image/algorithm/may_overlap.hpp>
#include <mizuiro/image/algorithm/transform.hpp>
#include <mizuiro/image/algorithm/uninitialized.hpp>
#include <mizuiro/image/algorithm/detail/copy_element.hpp>
#include <mizuiro/image/algorithm/detail/copy_element_overlapping.hpp>
#include <mizuiro/image/types/value_type.hpp>


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
	mizuiro::image::algorithm::may_overlap const _overlap,
	mizuiro::image::algorithm::uninitialized const _uninitialized
)
{
	mizuiro::image::algorithm::make_iterator_identity const make_iterator{};

	switch(
		_overlap
	)
	{
	case mizuiro::image::algorithm::may_overlap::yes:
		mizuiro::image::algorithm::transform(
			_src,
			_dest,
			mizuiro::image::algorithm::detail::copy_element_overlapping<
				mizuiro::image::types::value_type<
					typename ViewS::format
				>
			>(),
			make_iterator,
			_uninitialized
		);
		return;
	case mizuiro::image::algorithm::may_overlap::no:
		mizuiro::image::algorithm::transform(
			_src,
			_dest,
			mizuiro::image::algorithm::detail::copy_element{},
			make_iterator,
			_uninitialized
		);
		return;
	};
}

}
}
}

#endif
