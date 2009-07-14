#ifndef MIZUIRO_IMAGE_LINEAR_ITERATOR_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_LINEAR_ITERATOR_IMPL_HPP_INCLUDED

#include <mizuiro/image/linear_iterator_decl.hpp>

template<
	typename Format,
	typename Constness
>
mizuiro::image::linear_iterator<Format, Constness>::linear_iterator(
	pointer const data_
)
:
	data_(data_)
{}

template<
	typename Format,
	typename Constness
>
void
mizuiro::image::linear_iterator<Format, Constness>::advance(
	difference_type	const diff
)
{
	data_ += diff * Format::color_format::element_count;
}
	
template<
	typename Format,
	typename Constness
>
void
mizuiro::image::linear_iterator<Format, Constness>::increment()
{
	advance(1);
}

template<
	typename Format,
	typename Constness
>
void
mizuiro::image::linear_iterator<Format, Constness>::decrement()
{
	advance(-1);
}

template<
	typename Format,
	typename Constness
>
typename mizuiro::image::linear_iterator<Format, Constness>::difference_type
mizuiro::image::linear_iterator<Format, Constness>::distance_to(
	linear_iterator const &other
) const
{
	return other.data_ - data_;
}

template<
	typename Format,
	typename Constness
>
typename mizuiro::image::linear_iterator<Format, Constness>::reference
mizuiro::image::linear_iterator<Format, Constness>::dereference() const
{
	return reference(
		data_
	);
}

template<
	typename Format,
	typename Constness
>
bool
mizuiro::image::linear_iterator<Format, Constness>::equal(
	linear_iterator const &other
) const
{
	return data_ == other.data_;
}

#endif
