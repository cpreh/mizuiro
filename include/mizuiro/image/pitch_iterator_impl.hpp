#ifndef MIZUIR_IMAGE_PITCH_ITERATOR_IMPL_HPP_INCLUDED
#define MIZUIR_IMAGE_PITCH_ITERATOR_IMPL_HPP_INCLUDED

#include <mizuiro/image/pitch_iterator_decl.hpp>
#include <numeric>
#include <functional>

template<
	typename Format,
	typename Constness
>
mizuiro::image::pitch_iterator<Format, Constness>::pitch_iterator(
	dim_type const &dim_,
	pointer const data_,
	pointer const begin_,
	pitch_type const &pitch_
)
:
	dim_(dim_),
	data_(data_),
	begin_(begin_),
	pitch_(pitch_)
{}

template<
	typename Format,
	typename Constness
>
void
mizuiro::image::pitch_iterator<Format, Constness>::advance(
	difference_type const diff
)
{
	for(
		size_type i = 0;
		i < pitch_type::static_size;
		++i
	)
		data_ += (
			(diff +
				(data_ - begin_)
				% std::accumulate(
					dim_.begin(),
					dim_.begin() + i + 1,
					1,
					std::multiplies<
						size_type
					>()
				)
			) / dim_[i]
		) * pitch_[i];

	data_ += diff;
}

template<
	typename Format,
	typename Constness
>
void
mizuiro::image::pitch_iterator<Format, Constness>::increment()
{
	advance(1);
}

template<
	typename Format,
	typename Constness
>
void
mizuiro::image::pitch_iterator<Format, Constness>::decrement()
{
	advance(-1);
}

template<
	typename Format,
	typename Constness
>
typename mizuiro::image::pitch_iterator<Format, Constness>::difference_type
mizuiro::image::pitch_iterator<Format, Constness>::distance_to(
	pitch_iterator const &other
) const
{
	return other.data_ - data_;
}

template<
	typename Format,
	typename Constness
>
typename mizuiro::image::pitch_iterator<Format, Constness>::reference
mizuiro::image::pitch_iterator<Format, Constness>::dereference() const
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
mizuiro::image::pitch_iterator<Format, Constness>::equal(
	pitch_iterator const &other
) const
{
	return data_ == other.data_;
}

#endif
