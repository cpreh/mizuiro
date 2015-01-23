//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_COPY_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_COPY_HPP_INCLUDED

#include <mizuiro/image/algorithm/can_copy.hpp>
#include <mizuiro/image/algorithm/may_overlap.hpp>
#include <mizuiro/image/algorithm/uninitialized.hpp>
#include <mizuiro/image/algorithm/detail/copy_impl.hpp>


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
inline
void
copy(
	ViewS const &_src,
	ViewD const &_dest,
	mizuiro::image::algorithm::may_overlap const _overlap,
	mizuiro::image::algorithm::uninitialized const _uninitialized
)
{
	static_assert(
		mizuiro::image::algorithm::can_copy<
			ViewS,
			ViewD
		>::value,
		"Views must be compatible"
	);

	mizuiro::image::algorithm::detail::copy_impl(
		_src,
		_dest,
		_overlap,
		_uninitialized
	);
}

}
}
}

#endif
