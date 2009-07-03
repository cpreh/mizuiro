#ifndef MIZUIRO_IMAGE_DETAIL_ITERATOR_DIFFERENCE_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_ITERATOR_DIFFERENCE_HPP_INCLUDED

namespace mizuiro
{
namespace image
{
namespace detail
{

template<
	typename DifferenceType
>
struct iterator_difference {
	typedef DifferenceType result_type;

	template<
		typename T1,
		typename T2
	>
	result_type
	operator()(
		T1 const &,
		T2 const &
	) const
	{
		// TODO: error
	}

	template<
		typename T
	>
	result_type
	operator()(
		T const &a,
		T const &b
	) const
	{
		return b - a;
	}
};

}
}
}

#endif
