#ifndef MIZUIRO_IMAGE_PITCH_ITERATOR_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_PITCH_ITERATOR_IMPL_HPP_INCLUDED

#include <mizuiro/image/detail/iterator_position_distance.hpp>
#include <mizuiro/image/dimension_impl.hpp>
#include <mizuiro/image/pitch_iterator_decl.hpp>
#include <mizuiro/image/iterator_position.hpp>
#include <numeric>
#include <functional>
#include <cassert>

template<
	typename Format,
	typename Constness
>
mizuiro::image::pitch_iterator<Format, Constness>::pitch_iterator(
	dim_type const &dim_,
	pointer const data_,
	pitch_type const &pitch_
)
:
	dim_(dim_),
	data_(data_),
	root_data_(data_),
	pitch_(pitch_),
	stacked_dim_()
{
	for(
		size_type i = 0;
		i < pitch_type::static_size;
		++i
	)
		stacked_dim_[i] =
			std::accumulate(
				dim_.begin(),
				dim_.begin() + i + 1,
				1,
				std::multiplies<
					size_type
				>()
			);
}

template<
	typename Format,
	typename Constness
>
typename mizuiro::image::pitch_iterator<Format, Constness>::dim_type const &
mizuiro::image::pitch_iterator<Format, Constness>::dim() const
{
	return dim_;
}

template<
	typename Format,
	typename Constness
>
typename mizuiro::image::pitch_iterator<Format, Constness>::pointer
mizuiro::image::pitch_iterator<Format, Constness>::data() const
{
	return data_;
}

template<
	typename Format,
	typename Constness
>
typename mizuiro::image::pitch_iterator<Format, Constness>::pointer
mizuiro::image::pitch_iterator<Format, Constness>::root_data() const
{
	return root_data_;
}

template<
	typename Format,
	typename Constness
>
typename mizuiro::image::pitch_iterator<Format, Constness>::pitch_type const &
mizuiro::image::pitch_iterator<Format, Constness>::pitch() const
{
	return pitch_;
}

template<
	typename Format,
	typename Constness
>
void
mizuiro::image::pitch_iterator<Format, Constness>::advance(
	difference_type const diff
)
{
	assert(dim_.content());

	size_type const stride(
		Format::color_format::element_count
	);

	difference_type add = diff * stride;

	difference_type const diff_to_begin(
		detail::iterator_position_distance(
			dim_,
			iterator_position(
				*this
			),
			dim_type::null()
		)
	);

	for(
		size_type i = 0;
		i < pitch_type::static_size;
		++i
	)
	{
		add += (
			(diff +
				diff_to_begin
				% stacked_dim_[i]
			) / stacked_dim_[i]
		) * pitch_[i];
	}

	data_ += add;
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
	return detail::iterator_position_distance(
		dim_,
		iterator_position(
			*this
		),
		iterator_position(
			other
		)
	);
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
