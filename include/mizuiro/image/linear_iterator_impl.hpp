#ifndef MIZUIRO_IMAGE_LINEAR_ITERATOR_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_LINEAR_ITERATOR_IMPL_HPP_INCLUDED

#include <mizuiro/image/linear_iterator_decl.hpp>
#include <mizuiro/access/color_pointer.hpp>

template<
	typename Access,
	typename Format,
	typename Constness
>
mizuiro::image::linear_iterator<Access, Format, Constness>::linear_iterator(
	pointer const data_
)
:
	data_(data_)
{}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename mizuiro::image::linear_iterator<Access, Format, Constness>::pointer
mizuiro::image::linear_iterator<Access, Format, Constness>::data() const
{
	return data_;
}

template<
	typename Access,
	typename Format,
	typename Constness
>
void
mizuiro::image::linear_iterator<Access, Format, Constness>::advance(
	difference_type	const diff
)
{
	data_ += diff * Format::color_format::element_count;
}
	
template<
	typename Access,
	typename Format,
	typename Constness
>
void
mizuiro::image::linear_iterator<Access, Format, Constness>::increment()
{
	advance(1);
}

template<
	typename Access,
	typename Format,
	typename Constness
>
void
mizuiro::image::linear_iterator<Access, Format, Constness>::decrement()
{
	advance(-1);
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename mizuiro::image::linear_iterator<Access, Format, Constness>::difference_type
mizuiro::image::linear_iterator<Access, Format, Constness>::distance_to(
	linear_iterator const &other
) const
{
	return other.data_ - data_;
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename mizuiro::image::linear_iterator<Access, Format, Constness>::reference
mizuiro::image::linear_iterator<Access, Format, Constness>::dereference() const
{
	return
		reference(
			color_pointer(
				Access(),
				Format(),
				Constness(),
				data_
			)
		);
}

template<
	typename Access,
	typename Format,
	typename Constness
>
bool
mizuiro::image::linear_iterator<Access, Format, Constness>::equal(
	linear_iterator const &other
) const
{
	return data_ == other.data_;
}

#endif
