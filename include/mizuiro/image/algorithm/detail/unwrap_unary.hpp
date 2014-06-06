//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_DETAIL_UNWRAP_UNARY_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_DETAIL_UNWRAP_UNARY_HPP_INCLUDED

#include <mizuiro/detail/nonassignable.hpp>
#include <mizuiro/image/algorithm/detail/unary_fold.hpp>


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
	typename State
>
class unwrap_unary
{
	MIZUIRO_DETAIL_NONASSIGNABLE(
		unwrap_unary
	);
public:
	unwrap_unary(
		Function const &_function,
		State _state
	)
	:
		function_(
			_function
		),
		state_(
			_state
		)
	{
	}

	typedef
	State
	result_type;

	template<
		typename View
	>
	result_type
	operator()(
		View const &_view
	) const
	{
		return
			mizuiro::image::algorithm::detail::unary_fold(
				function_,
				state_,
				_view
			);
	}
private:
	Function const &function_;

	State state_;
};

}
}
}
}

#endif
