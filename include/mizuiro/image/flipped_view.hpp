//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FLIPPED_VIEW_HPP_INCLUDED
#define MIZUIRO_IMAGE_FLIPPED_VIEW_HPP_INCLUDED

#include <mizuiro/image/view_impl.hpp>
#include <mizuiro/image/dimension_impl.hpp>
#include <mizuiro/image/move_iterator.hpp>
#include <mizuiro/image/detail/flipped_edge.hpp>
#include <mizuiro/image/detail/flipped_pitch.hpp>
#include <mizuiro/image/detail/flipped_start.hpp>
#include <boost/utility/enable_if.hpp>
#include <iterator>

namespace mizuiro
{
namespace image
{

template<
	typename View
>
typename boost::enable_if_c<
	View::dim_type::static_size >= 2,
	View const
>::type
flipped_view(
	View const &_view
)
{
	typedef typename View::dim_type dim_type;

	typename dim_type::value_type const last_dim(
		_view.dim().back()
	);

	return
		last_dim > 1
		?
			View(
				_view.dim(),
				mizuiro::image::move_iterator(
					_view,
					mizuiro::image::detail::flipped_start<
						dim_type
					>(
						last_dim
					)
				).data(),
				mizuiro::image::detail::flipped_pitch(
					_view.pitch(),
					std::distance(
						mizuiro::image::move_iterator(
							_view,
							mizuiro::image::detail::flipped_edge(
								_view.dim()
							)
						).data(),
						_view.begin().data()
					)
					+
					_view.pitch().back()
				)
			)
		:
			_view;
}

}
}

#endif
