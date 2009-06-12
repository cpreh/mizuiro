#ifndef MIZUIRO_IMAGE_VIEW_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_VIEW_IMPL_HPP_INCLUDED

#include <mizuiro/image/view_decl.hpp>

/*
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
typename mizuiro::image::view<Format, Constness>::iterator
mizuiro::image::view<Format, Constness>::begin() const
{
	return iterator(
		dim(),
		data_,
		data_,
		pitch_
	);
}

template<
	typename Format,
	typename Constness
>
typename mizuiro::image::view<Format, Constness>::iterator
mizuiro::image::view<Format, Constness>::end() const
{
	return begin() + dim().content();
}

template<
	typename Format,
	typename Constness
>
typename mizuiro::image::view<Format, Constness>::reference
mizuiro::image::view<Format, Constness>::operator[](
	dim_type const &index
) const
{
	// TODO: do the same stuff as in the iterator here?
}

template<
	typename Format,
	typename Constness
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
			throw foobar();
	
	return (*this)[index];
}
*/

#endif
