//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_DETAIL_APPLY_UNARY_ITERATION_FUN_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_DETAIL_APPLY_UNARY_ITERATION_FUN_HPP_INCLUDED

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
class apply_unary_iteration_fun {
public:
	explicit apply_unary_iteration_fun(
		Function const &fun
	)
	:
		fun(fun)
	{}

	typedef void result_type;

	template<
		typename T
	>
	result_type
	operator()(
		T const &range
	) const
	{
		typename T::iterator const end(
			range.end()
		);

		for(
			typename T::iterator it(
				range.begin()
			);
			it != end;
			++it
		)
			fun(
				*it
			);
	}
private:
	Function const fun;
};

}
}
}
}

#endif
