#ifndef MIZUIRO_IMAGE_DETAIL_INCREMENT_ITERATOR_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_INCREMENT_ITERATOR_HPP_INCLUDED

namespace mizuiro
{
namespace image
{
namespace detail
{

template<
	typename Variant
>
struct increment_iterator {
	typedef Variant result_type;

	template<
		typename T
	>
	result_type
	operator()(
		T t
	) const
	{
		return ++t;
	}
};

}
}
}

#endif
