#ifndef MIZUIRO_IMAGE_DETAIL_COMPARE_ITERATOR_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_COMPARE_ITERATOR_HPP_INCLUDED

namespace mizuiro
{
namespace image
{
namespace detail
{

struct compare_iterator {
	typedef bool result_type;

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
		return false;
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
		return a == b;
	}
};

}
}
}

#endif
