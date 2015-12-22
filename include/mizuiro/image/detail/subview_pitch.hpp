//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_DETAIL_SUBVIEW_PITCH_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_SUBVIEW_PITCH_HPP_INCLUDED

#include <mizuiro/no_init.hpp>
#include <mizuiro/image/bound_impl.hpp>
#include <mizuiro/image/dimension_impl.hpp>
#include <mizuiro/image/move_iterator.hpp>
#include <mizuiro/image/detail/edge_pos_begin.hpp>
#include <mizuiro/image/detail/edge_pos_end.hpp>
#include <mizuiro/image/detail/pitch_difference.hpp>


namespace mizuiro
{
namespace image
{
namespace detail
{

template<
	typename View
>
typename
View::pitch_type
subview_pitch(
	View const &_view,
	typename View::bound_type const &_bound
)
{
	typedef typename View::pitch_type pitch_type;

	pitch_type ret{
		mizuiro::no_init{}
	};

	for(
		typename pitch_type::size_type index = 0;
		index < pitch_type::static_size;
		++index
	)
	{
		typename View::dim const edge_pos_end(
			mizuiro::image::detail::edge_pos_end(
				_bound,
				index
			)
		);

		ret[
			index
		] =
			_view.size()[
				index
			] > 1
			?
				mizuiro::image::detail::pitch_difference(
					mizuiro::image::move_iterator(
						_view,
						edge_pos_end
					),
					mizuiro::image::move_iterator(
						_view,
						mizuiro::image::detail::edge_pos_begin(
							_bound,
							index
						)
					)
				)
			:
				0
			;

		// if the end is one past the parent view's dim,
		// the pitch will be skipped by the iterator, so readd it
		if(
			edge_pos_end[
				index
			]
			==
			_view.size()[
				index
			]
		)
			ret[
				index
			]
				+=
				_view.pitch()[
					index
				];
	}

	return ret;
}

}
}
}

#endif
