//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_DETAIL_SUBVIEW_PITCH_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_SUBVIEW_PITCH_HPP_INCLUDED

#include <mizuiro/image/detail/edge_pos_end.hpp>
#include <mizuiro/image/detail/edge_pos_begin.hpp>
#include <mizuiro/image/dimension_impl.hpp>
#include <mizuiro/image/bound_impl.hpp>
#include <mizuiro/image/move_iterator.hpp>
#include <iterator>

namespace mizuiro
{
namespace image
{
namespace detail
{

template<
	typename View
>
typename View::pitch_type const
subview_pitch(
	View const &_view,
	typename View::bound_type const &_bound
)
{
	typedef typename View::pitch_type pitch_type;

	pitch_type ret;

	for(
		typename pitch_type::size_type i = 0;
		i < pitch_type::static_size;
		++i
	)
	{
		typename View::dim const edge_pos_end(
			mizuiro::image::detail::edge_pos_end(
				_bound,
				i
			)
		);

		ret[i] =
			_view.size()[i] > 1
			?
				std::distance(
					mizuiro::image::move_iterator(
						_view,
						edge_pos_end
					).data(),
					mizuiro::image::move_iterator(
						_view,
						mizuiro::image::detail::edge_pos_begin(
							_bound,
							i
						)
					).data()
				)
			:
				0;

		// if the end is one past the parent view's dim,
		// the pitch will be skipped by the iterator, so readd it
		if(
			edge_pos_end[i] == _view.size()[i]
		)
			ret[i] += _view.pitch()[i];
	}

	return ret;
}

}
}
}

#endif
