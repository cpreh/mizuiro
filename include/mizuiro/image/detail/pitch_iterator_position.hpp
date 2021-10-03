//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_DETAIL_PITCH_ITERATOR_POSITION_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_PITCH_ITERATOR_POSITION_HPP_INCLUDED

#include <mizuiro/image/detail/pitch_iterator_fwd.hpp>
#include <mizuiro/image/detail/relative_position.hpp>


namespace mizuiro::image::detail
{

template<
	typename Access,
	typename Format,
	typename Constness
>
inline
typename
Format::dim
pitch_iterator_position(
	mizuiro::image::detail::pitch_iterator<
		Access,
		Format,
		Constness
	> const &_it
)
{
	return
		mizuiro::image::detail::relative_position(
			_it.size(),
			_it.offset()
		);
}

}

#endif
