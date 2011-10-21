//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_DETAIL_UNWRAP_BINARY_BOTH_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_DETAIL_UNWRAP_BINARY_BOTH_HPP_INCLUDED

#include <mizuiro/detail/nonassignable.hpp>
#include <mizuiro/image/algorithm/detail/binary_iteration.hpp>


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
class unwrap_binary_both
{
	MIZUIRO_DETAIL_NONASSIGNABLE(
		unwrap_binary_both
	);
public:
	explicit
	unwrap_binary_both(
		Function const &_function
	)
	:
		function_(_function)
	{
	}

	typedef void result_type;

	template<
		typename View1,
		typename View2
	>
	result_type
	operator()(
		View1 const &_view1,
		View2 const &_view2
	) const
	{
		return
			detail::binary_iteration(
				function_,
				_view1,
				_view2
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
