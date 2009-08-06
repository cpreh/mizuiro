#ifndef MIZUIRO_IMAGE_ALGORITHM_DETAIL_APPLY_TERNARY_ITERATION_FUN_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_DETAIL_APPLY_TERNARY_ITERATION_FUN_HPP_INCLUDED

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
class apply_ternary_iteration_fun {
public:
	apply_ternary_iteration_fun()
	:
		fun()
	{}

	explicit apply_ternary_iteration_fun(
		Function const &fun
	)
	:
		fun(fun)
	{}

	typedef void result_type;

	template<
		typename T1,
		typename T2,
		typename T3
	>
	result_type
	operator()(
		T1 const &range1,
		T2 const &range2,
		T3 const &range3
	) const
	{
		typename T2::iterator it2(
			range2.begin()
		);

		typename T3::iterator it3(
			range3.begin()
		);

		for(
			typename T1::iterator it1(
				range1.begin()
			);
			it1 != range1.end();
			++it1, ++it2, ++it3
		)
			fun(
				*it1,
				*it2,
				*it3
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
