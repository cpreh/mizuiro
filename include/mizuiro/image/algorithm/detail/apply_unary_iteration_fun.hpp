//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_DETAIL_APPLY_UNARY_ITERATION_FUN_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_DETAIL_APPLY_UNARY_ITERATION_FUN_HPP_INCLUDED

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
class apply_unary_iteration_fun
{
	MIZUIRO_DETAIL_NONASSIGNABLE(
		apply_unary_iteration_fun
	);
public:
	explicit apply_unary_iteration_fun(
		Function const &_fun
	)
	:
		fun_(_fun)
	{}

	typedef void result_type;

	template<
		typename T
	>
	result_type
	operator()(
		T const &_range
	) const
	{
		typename T::iterator const end(
			_range.end()
		);

		for(
			typename T::iterator it(
				_range.begin()
			);
			it != end;
			++it
		)
			fun_(
				*it
			);
	}
private:
	Function const fun_;
};

}
}
}
}

#endif
