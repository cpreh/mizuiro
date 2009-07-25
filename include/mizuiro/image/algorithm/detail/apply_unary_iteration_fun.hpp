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
		for(
			typename T::iterator it(
				range.begin()
			);
			it != range.end();
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
