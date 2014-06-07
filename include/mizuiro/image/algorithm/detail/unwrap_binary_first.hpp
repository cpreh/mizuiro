//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_DETAIL_UNWRAP_BINARY_FIRST_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_DETAIL_UNWRAP_BINARY_FIRST_HPP_INCLUDED

#include <mizuiro/detail/nonassignable.hpp>
#include <mizuiro/image/algorithm/detail/binary_fold.hpp>


namespace mizuiro
{
namespace image
{
namespace algorithm
{
namespace detail
{

template<
	typename Function,
	typename State,
	typename View2
>
class unwrap_binary_first
{
	MIZUIRO_DETAIL_NONASSIGNABLE(
		unwrap_binary_first
	);
public:
	unwrap_binary_first(
		Function const &_function,
		State _state,
		View2 const &_view2
	)
	:
		function_(
			_function
		),
		state_(
			_state
		),
		view2_(
			_view2
		)
	{
	}

	typedef
	State
	result_type;

	template<
		typename View1
	>
	result_type
	operator()(
		View1 const &_view1
	) const
	{
		return
			mizuiro::image::algorithm::detail::binary_fold(
				function_,
				state_,
				_view1,
				view2_
			);
	}
private:
	Function const &function_;

	State state_;

	View2 const &view2_;
};

}
}
}
}

#endif
