//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_DETAIL_PITCH_ITERATOR_POSITION_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_PITCH_ITERATOR_POSITION_HPP_INCLUDED

#include <mizuiro/image/detail/relative_position.hpp>
#include <mizuiro/image/pitch_iterator_fwd.hpp>

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
typename Format::dim_type const
pitch_iterator_position(
	image::pitch_iterator<
		Access,
		Format,
		Constness
	> const &_it
)
{
	return
		image::detail::relative_position(
			_it.dim(),
			_it.offset()
		);
}

}
}
}

#endif
