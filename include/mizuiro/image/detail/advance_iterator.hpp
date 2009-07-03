#ifndef MIZUIRO_IMAGE_DETAIL_ADVANCE_ITERATOR_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_ADVANCE_ITERATOR_HPP_INCLUDED

namespace mizuiro
{
namespace image
{
namespace detail
{

template<
	typename Variant,
	typename DifferenceType
>
struct advance_iterator {
	typedef Variant result_type;

	explicit advance_iterator(
		DifferenceType diff
	)
	:
		diff(diff)
	{}

	template<
		typename T
	>
	result_type
	operator()(
		T t
	) const
	{
		return t += diff;	
	}
private:
	DifferenceType const diff;
};

}
}
}

#endif
