//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_MOVE_ITERATOR_HPP_INCLUDED
#define MIZUIRO_IMAGE_MOVE_ITERATOR_HPP_INCLUDED

namespace mizuiro
{
namespace image
{

template<
	typename View
>
typename View::iterator
move_iterator(
	View const &_view,
	typename View::dim_type const &_pos
)
{
	typename View::iterator ret(
		_view.begin()
	);

	typedef typename View::dim_type dim_type;

	dim_type const dim(
		_view.dim()
	);

	typedef typename View::iterator::difference_type difference_type;

	difference_type
		add = 0,
		multiplier = 1;

	for(
		typename dim_type::size_type i = 0;
		i < dim_type::static_size;
		++i
	)
	{
		add +=
			static_cast<
				difference_type
			>(
				_pos[i]
			)
			* multiplier;

		multiplier *=
			static_cast<
				difference_type
			>(
				dim[i]
			);
	}

	ret += add;

	return ret;
}

}
}

#endif
