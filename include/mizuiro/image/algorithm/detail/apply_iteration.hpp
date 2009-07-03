#ifndef MIZUIRO_IMAGE_ALGORITHM_DETAIL_APPLY_ITERATION_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_DETAIL_APPLY_ITERATION_HPP_INCLUDED

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
class apply_iteration {
public:
	explicit apply_iteration(
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
		T begin,
		T const &end
	) const
	{
		while(
			begin != end
		)
			fun(
				*begin++
			);
	}

	template<
		typename T1,
		typename T2
	>
	result_type
	operator()(
		T1,
		T2
	) const
	{
		// TODO: error!
	}
private:
	Function const fun;
};

}
}
}
}

#endif
