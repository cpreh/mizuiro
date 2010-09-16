//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_DETAIL_APPLY_BINARY_ITERATION_FUN_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_DETAIL_APPLY_BINARY_ITERATION_FUN_HPP_INCLUDED

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
class apply_binary_iteration_fun
{
	MIZUIRO_DETAIL_NONASSIGNABLE(
		apply_binary_iteration_fun
	);
public:
	apply_binary_iteration_fun()
	:
		fun_()
	{}

	explicit apply_binary_iteration_fun(
		Function const &_fun
	)
	:
		fun_(_fun)
	{}

	typedef void result_type;

	template<
		typename T1,
		typename T2
	>
	result_type
	operator()(
		T1 const &_range1,
		T2 const &_range2
	) const
	{
		typename T2::iterator it2(
			_range2.begin()
		);

		typename T1::iterator const end1(
			_range1.end()
		);

		for(
			typename T1::iterator it1(
				_range1.begin()
			);
			it1 != end1;
			++it1, ++it2
		)
			fun_(
				*it1,
				*it2
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
