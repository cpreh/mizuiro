//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ITERATOR_POSITION_HPP_INCLUDED
#define MIZUIRO_IMAGE_ITERATOR_POSITION_HPP_INCLUDED

#include <mizuiro/image/detail/iterator_position.hpp>
#include <mizuiro/image/detail/linear_iterator_position.hpp>
#include <mizuiro/image/detail/pitch_iterator_position.hpp>
#include <mizuiro/image/iterator_fwd.hpp>
#include <mizuiro/image/linear_iterator_fwd.hpp>
#include <mizuiro/image/pitch_iterator_fwd.hpp>
#include <mizuiro/image/view_fwd.hpp>
#include <mizuiro/detail/variant_apply_unary.hpp>

namespace mizuiro
{
namespace image
{

template<
	typename Access,
	typename Format,
	typename Constness
>
typename Format::dim_type const
iterator_position(
	image::view<
		Access,
		Format,
		Constness
	> const &_view,
	image::linear_iterator<
		Access,
		Format,
		Constness
	> const &_it
)
{
	return
		detail::linear_iterator_position(
			_view.dim(),
			_it - _view.begin()
		);
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename Format::dim_type const
iterator_position(
	image::view<
		Access,
		Format,
		Constness
	> const &,
	image::pitch_iterator<
		Access,
		Format,
		Constness
	> const &_it
)
{
	return
		image::detail::pitch_iterator_position(
			_it.dim(),
			_it.offset()
		);
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename Format::dim_type const
iterator_position(
	image::view<
		Access,
		Format,
		Constness
	> const &_view,
	image::iterator<
		Access,
		Format,
		Constness
	> const &_it
)
{
	return
		mizuiro::detail::variant_apply_unary(
			image::detail::iterator_position
			<
				image::view
				<
					Access,
					Format,
					Constness
				>
			>(
				_view
			),
			_it.internal()
		);
}

}
}

#endif
