//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_DETAIL_ITERATOR_POSITION_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_ITERATOR_POSITION_HPP_INCLUDED

#include <mizuiro/image/detail/linear_iterator_position.hpp>
#include <mizuiro/image/detail/pitch_iterator_position.hpp>
#include <mizuiro/detail/nonassignable.hpp>

namespace mizuiro
{
namespace image
{
namespace detail
{

template<
	typename View
>
class iterator_difference
{
	MIZUIRO_DETAIL_NONASSIGNABLE(
		iterator_difference
	);
public:
	explicit iterator_difference(
		View const &_view
	)
	:
		view_(_view)
	{
	}
		
	typedef typename View::dim_type result_type;

	result_type
	operator()(
		typename View::liner_iterator const _it
	) const
	{
		return
			mizuiro::image::detail::linear_iterator_position(
				view_,
				_it
			);
	}

	result_type
	operator()(
		typename View::pitch_iterator const _it
	) const
	{
		return
			mizuiro::image::detail::pitch_iterator_position(
				view_,
				_it
			);
	}
private:
	View const &view_;
};

}
}
}

#endif
