#ifndef MIZUIRO_IMAGE_ALGORITHM_DETAIL_TRANSFORM_BINARY_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_DETAIL_TRANSFORM_BINARY_HPP_INCLUDED

namespace mizuiro
{
namespace image
{
namespace algorithm
{
namespace detail
{

template<
	typename Fun
>
struct transform_binary {
	typedef void result_type;

	explicit transform_binary(
		Fun const &fun
	)
	:
		fun(fun)
	{}

	template<
		typename Source,
		typename Dest
	>
	result_type
	operator()(
		Source const &source,
		Dest const &dest
	) const
	{
		fun(
			source,
			dest
		);
	}
private:
	Fun const &fun;
};

}
}
}
}

#endif
