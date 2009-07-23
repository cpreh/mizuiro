#ifndef MIZUIRO_IMAGE_DETAIL_ITERATOR_DATA_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_ITERATOR_DATA_HPP_INCLUDED

namespace mizuiro
{
namespace image
{
namespace detail
{

template<
	typename Pointer
>
struct iterator_data {
	typedef Pointer result_type;

	template<
		typename T
	>
	result_type
	operator()(
		T const &t
	) const
	{
		return t.data();
	}
};

}
}
}

#endif
