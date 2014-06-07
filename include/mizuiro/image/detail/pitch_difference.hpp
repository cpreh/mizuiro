//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_DETAIL_PITCH_DIFFERENCE_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_PITCH_DIFFERENCE_HPP_INCLUDED

#include <mizuiro/detail/external_begin.hpp>
#include <iterator>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace image
{
namespace detail
{

template<
	typename Iterator
>
typename Iterator::difference_type
pitch_difference(
	Iterator const _begin,
	Iterator const _end
)
{
	return
		std::distance(
			_begin.data(),
			_end.data()
		);
}

}
}
}

#endif
