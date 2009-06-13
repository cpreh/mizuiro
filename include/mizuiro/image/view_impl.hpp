#ifndef MIZUIRO_IMAGE_VIEW_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_VIEW_IMPL_HPP_INCLUDED

#include <mizuiro/image/view_decl.hpp>
#include <stdexcept>

template<
	typename Iterator
>
mizuiro::image::view<Iterator>::view(
	dim_type const &dim_,
	pointer const data_,
	pitch_type const &pitch_
)
:
	dim_(dim_),
	data_(data_),
	pitch_(pitch_)
{}

template<
	typename Iterator
>
typename mizuiro::image::view<Iterator>::dim_type const &
mizuiro::image::view<Iterator>::dim() const
{
	return dim_;
}

template<
	typename Iterator
>
typename mizuiro::image::view<Iterator>::iterator const
mizuiro::image::view<Iterator>::begin() const
{
	return iterator(
		dim(),
		data_,
		data_,
		pitch_
	);
}

template<
	typename Iterator
>
typename mizuiro::image::view<Iterator>::iterator const
mizuiro::image::view<Iterator>::end() const
{
	return begin() + dim().content();
}

template<
	typename Iterator
>
typename mizuiro::image::view<Iterator>::reference
mizuiro::image::view<Iterator>::operator[](
	dim_type const &index
) const
{
	// TODO: do the same stuff as in the iterator here?
}

template<
	typename Iterator
>
typename mizuiro::image::view<Iterator>::reference
mizuiro::image::view<Iterator>::at(
	dim_type const &index
) const
{
	for(
		size_type i = 0;
		i < dim_type::dim_wrapper::value;
		++i
	)
		if(index[i] >= dim[i])
			throw std::range_error();
	
	return (*this)[index];
}

#endif
