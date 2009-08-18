#ifndef MIZUIRO_IMAGE_PITCH_ITERATOR_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_PITCH_ITERATOR_IMPL_HPP_INCLUDED

#include <mizuiro/image/dimension_impl.hpp>
#include <mizuiro/image/increment_iterator_decl.hpp>
#include <numeric>
#include <functional>
#include <cassert>

template<
	typename Format,
	typename Constness
>
mizuiro::image::increment_iterator<Format, Constness>::increment_iterator(
	dim_type const &dim_,
	pointer const data_,
	pitch_type const &pitch_
)
:
	dim_(dim_),
	data_(data_),
	root_data_(data_),
	pitch_(pitch_)
{}

template<
	typename Format,
	typename Constness
>
typename mizuiro::image::increment_iterator<Format, Constness>::dim_type const &
mizuiro::image::increment_iterator<Format, Constness>::dim() const
{
	return dim_;
}

template<
	typename Format,
	typename Constness
>
typename mizuiro::image::increment_iterator<Format, Constness>::pointer
mizuiro::image::increment_iterator<Format, Constness>::data() const
{
	return data_;
}

template<
	typename Format,
	typename Constness
>
typename mizuiro::image::increment_iterator<Format, Constness>::pointer
mizuiro::image::increment_iterator<Format, Constness>::root_data() const
{
	return root_data_;
}

template<
	typename Format,
	typename Constness
>
typename mizuiro::image::increment_iterator<Format, Constness>::pitch_type const &
mizuiro::image::increment_iterator<Format, Constness>::pitch() const
{
	return pitch_;
}

template<
	typename Format,
	typename Constness
>
void
mizuiro::image::increment_iterator<Format, Constness>::increment()
{
	++line_advance;

	if(
		line_advance / stacked_dim_[0]
	)
	{
		difference_type add = 0;

		for(
			size_type i = 0;
			i < pitch_type::static_size;
			++i
		)
			
		add += 
		line_advance = 0;		
	}
}

template<
	typename Format,
	typename Constness
>
typename mizuiro::image::increment_iterator<Format, Constness>::reference
mizuiro::image::increment_iterator<Format, Constness>::dereference() const
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
mizuiro::image::increment_iterator<Format, Constness>::equal(
	increment_iterator const &other
) const
{
	return data_ == other.data_;
}

#endif
