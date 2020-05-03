//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_MAKE_ITERATOR_INDEXED_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_MAKE_ITERATOR_INDEXED_HPP_INCLUDED

#include <mizuiro/image/dimension_null.hpp>
#include <mizuiro/image/indexed_iterator_impl.hpp>
#include <mizuiro/image/iterator_position.hpp>


namespace mizuiro
{
namespace image
{
namespace algorithm
{

struct make_iterator_indexed
{
	template<
		typename View
	>
	static
	mizuiro::image::indexed_iterator<
		typename View::dim,
		typename View::iterator
	>
	begin(
		View const &_view
	)
	{
		using
		result_type
		=
		mizuiro::image::indexed_iterator<
			typename View::dim,
			typename View::iterator
		>;

		return
			result_type(
				_view.size(),
				mizuiro::image::dimension_null<
					typename
					View::dim
				>(),
				_view.begin()
			);
	}

	template<
		typename View
	>
	static
	mizuiro::image::indexed_iterator<
		typename View::dim,
		typename View::iterator
	>
	end(
		View const &_view
	)
	{
		using
		result_type
		=
		mizuiro::image::indexed_iterator<
			typename View::dim,
			typename View::iterator
		>;

		return
			result_type(
				_view.size(),
				mizuiro::image::iterator_position(
					_view,
					_view.end()
				),
				_view.end()
			);
	}
};

}
}
}

#endif
