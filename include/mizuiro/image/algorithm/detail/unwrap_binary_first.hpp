//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_DETAIL_UNWRAP_BINARY_FIRST_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_DETAIL_UNWRAP_BINARY_FIRST_HPP_INCLUDED

#include <mizuiro/image/algorithm/detail/binary_iteration.hpp>
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
	typename Function,
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
		View2 const &_view2
	)
	:
		function_(_function),
		view2_(_view2)
	{
	}

	typedef void result_type;

	template<
		typename View1
	>
	result_type
	operator()(
		View1 const &_view1
	) const
	{
		return
			detail::binary_iteration(
				function_,
				_view1,
				view2_
			);
	}
private:
	Function const &function_;

	View2 const &view2_;
};

}
}
}
}

#endif
