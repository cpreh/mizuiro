//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_DETAIL_UNWRAP_UNARY_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_DETAIL_UNWRAP_UNARY_HPP_INCLUDED

#include <mizuiro/image/algorithm/detail/unary_iteration.hpp>
#include <mizuiro/detail/nonassignable.hpp>

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
class unwrap_unary
{
	MIZUIRO_DETAIL_NONASSIGNABLE(
		unwrap_unary
	);
public:
	explicit
	unwrap_unary(
		Function const &_function
	)
	:
		function_(_function)
	{
	}

	typedef void result_type;

	template<
		typename View
	>
	result_type
	operator()(
		View const &_view
	) const
	{
		return
			detail::unary_iteration(
				function_,
				_view
			);
	}
private:
	Function const &function_;
};

}
}
}
}

#endif
