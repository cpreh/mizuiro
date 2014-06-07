//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_DETAIL_ITERATION_TO_FOLD_FUNCTION_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_DETAIL_ITERATION_TO_FOLD_FUNCTION_HPP_INCLUDED

#include <mizuiro/detail/nonassignable.hpp>
#include <mizuiro/image/algorithm/detail/dummy_state.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <utility>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace image
{
namespace algorithm
{
namespace detail
{

template<
	typename Function
>
class iteration_to_fold_function
{
	MIZUIRO_DETAIL_NONASSIGNABLE(
		iteration_to_fold_function
	);
public:
	explicit
	iteration_to_fold_function(
		Function const &_function
	)
	:
		function_(
			_function
		)
	{
	}

	typedef
	mizuiro::image::algorithm::detail::dummy_state
	result_type;

	template<
		typename... Args
	>
	result_type
	operator()(
		mizuiro::image::algorithm::detail::dummy_state,
		Args && ..._args
	) const
	{
		function_(
			std::forward<
				Args
			>(
				_args
			)...
		);

		return
			mizuiro::image::algorithm::detail::dummy_state();
	}
private:
	Function const &function_;
};

}
}
}
}

#endif
