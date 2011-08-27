//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_DETAIL_LINEAR_ITERATOR_POSITION_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_LINEAR_ITERATOR_POSITION_HPP_INCLUDED

#include <mizuiro/image/detail/relative_position.hpp>
#include <mizuiro/image/linear_iterator_impl.hpp>
#include <mizuiro/image/linear_view_impl.hpp>

namespace mizuiro
{
namespace image
{
namespace detail
{

template<
	typename Access,
	typename Format,
	typename Constness
>
typename Format::dim const
linear_iterator_position(
	image::linear_view<
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
		detail::relative_position(
			_view.size(),
			_it
			-
			_view.begin()
		);
}

}
}
}

#endif
