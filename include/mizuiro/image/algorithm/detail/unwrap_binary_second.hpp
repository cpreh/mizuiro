//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_DETAIL_UNWRAP_BINARY_SECOND_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_DETAIL_UNWRAP_BINARY_SECOND_HPP_INCLUDED

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
	typename Function,
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
		View1 const &_view1
	)
	:
		function_(
			_function
		),
		view1_(
			_view1
		)
	{
	}

	typedef void result_type;

	template<
		typename View2
	>
	result_type
	operator()(
		View2 const &_view2
	) const
	{
		return
			mizuiro::image::algorithm::detail::binary_iteration(
				function_,
				view1_,
				_view2
			);
	}
private:
	Function const &function_;

	View1 const &view1_;
};

}
}
}
}

#endif
