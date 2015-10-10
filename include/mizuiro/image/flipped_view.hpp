//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FLIPPED_VIEW_HPP_INCLUDED
#define MIZUIRO_IMAGE_FLIPPED_VIEW_HPP_INCLUDED

#include <mizuiro/image/dimension_impl.hpp>
#include <mizuiro/image/move_iterator.hpp>
#include <mizuiro/image/pitch_view_impl.hpp>
#include <mizuiro/image/to_pitch_view.hpp>
#include <mizuiro/image/detail/flipped_edge.hpp>
#include <mizuiro/image/detail/flipped_pitch.hpp>
#include <mizuiro/image/detail/flipped_start.hpp>
#include <mizuiro/image/detail/pitch_difference.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <type_traits>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace image
{

template<
	typename View
>
typename
std::enable_if<
	View::dim::static_size >= 2,
	mizuiro::image::to_pitch_view<
		View
	>
>::type
flipped_view(
	View const &_view
)
{
	typedef
	mizuiro::image::to_pitch_view<
		View
	>
	result_type;

	typedef typename View::dim dim;

	typename dim::value_type const last_dim(
		_view.size().back()
	);

	return
		last_dim > 1
		?
			result_type(
				_view.size(),
				mizuiro::image::move_iterator(
					_view,
					mizuiro::image::detail::flipped_start<
						dim
					>(
						last_dim
					)
				).data(),
				mizuiro::image::detail::flipped_pitch(
					_view.pitch(),
					image::detail::pitch_difference(
						mizuiro::image::move_iterator(
							_view,
							mizuiro::image::detail::flipped_edge(
								_view.size()
							)
						),
						_view.begin()
					)
					+
					_view.pitch().back()
				)
			)
		:
			result_type(
				_view.size(),
				_view.data(),
				_view.pitch()
			)
		;
}

}
}

#endif
