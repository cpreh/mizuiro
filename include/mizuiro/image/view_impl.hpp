#ifndef MIZUIRO_IMAGE_VIEW_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_VIEW_IMPL_HPP_INCLUDED

#include <mizuiro/image/view_decl.hpp>
#include <mizuiro/image/iterator_impl.hpp>
#include <mizuiro/image/pitch_iterator_impl.hpp>
#include <mizuiro/image/linear_iterator_impl.hpp>
#include <stdexcept>

template<
	typename Format,
	typename Constness
>
mizuiro::image::view<Format, Constness>::view(
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
	typename Format,
	typename Constness
>
typename mizuiro::image::view<Format, Constness>::dim_type const &
mizuiro::image::view<Format, Constness>::dim() const
{
	return dim_;
}

template<
	typename Format,
	typename Constness
>
typename mizuiro::image::view<Format, Constness>::iterator const
mizuiro::image::view<Format, Constness>::begin() const
{
	return pitch_ == pitch_type::null()
		? iterator(
			linear_iterator<
				Format,
				Constness
			>(
				data_
			)
		)
		: iterator(
			pitch_iterator<
				Format,
				Constness
			>(
				dim(),
				data_,
				data_,
				pitch_
			)
		);
}

template<
	typename Format,
	typename Constness
>
typename mizuiro::image::view<Format, Constness>::iterator const
mizuiro::image::view<Format, Constness>::end() const
{
	return begin() + dim().content();
}

/*
template<
	typename Format, Constness
>
typename mizuiro::image::view<Format, Constness>::reference
mizuiro::image::view<Format, Constness>::operator[](
	dim_type const &index
) const
{
	// TODO: do the same stuff as in the iterator here?
}

template<
	typename Format, Constness
>
typename mizuiro::image::view<Format, Constness>::reference
mizuiro::image::view<Format, Constness>::at(
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
*/

template<
	typename Format,
	typename Constness
>
typename mizuiro::image::view<Format, Constness>::pointer
mizuiro::image::view<Format, Constness>::data() const
{
	return data_;
}

#endif
