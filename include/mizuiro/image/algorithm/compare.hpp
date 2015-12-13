//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_COMPARE_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_COMPARE_HPP_INCLUDED

#include <mizuiro/image/algorithm/binary_fold.hpp>
#include <mizuiro/image/algorithm/make_iterator_identity.hpp>


namespace mizuiro
{
namespace image
{
namespace algorithm
{

template<
	typename View1,
	typename View2,
	typename Compare
>
bool
compare(
	View1 const &_src1,
	View2 const &_src2,
	Compare const &_compare
)
{
	return
		mizuiro::image::algorithm::binary_fold(
			[
				&_compare
			](
				bool const _state,
				auto const &_src1_inner,
				auto const &_src2_inner
			)
			-> bool
			{
				return
					_state
					&&
					_compare(
						_src1_inner,
						_src2_inner
					);
			},
			true,
			_src1,
			_src2,
			mizuiro::image::algorithm::make_iterator_identity()
		);
}

}
}
}

#endif
