//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_DETAIL_UNWRAP_BINARY_SECOND_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_DETAIL_UNWRAP_BINARY_SECOND_HPP_INCLUDED

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
	typename View1
>
class unwrap_binary_second
{
	MIZUIRO_DETAIL_NONASSIGNABLE(
		unwrap_binary_second
	);
public:
	unwrap_binary_second(
		Function const &_function,
		State _state,
		View1 const &_view1
	)
	:
		function_(
			_function
		),
		state_(
			_state
		),
		view1_(
			_view1
		)
	{
	}

	typedef
	State
	result_type;

	template<
		typename View2
	>
	result_type
	operator()(
		View2 const &_view2
	) const
	{
		return
			mizuiro::image::algorithm::detail::binary_fold(
				function_,
				state_,
				view1_,
				_view2
			);
	}
private:
	Function const &function_;

	State state_;

	View1 const &view1_;
};

}
}
}
}

#endif
