#ifndef MIZUIRO_IMAGE_PITCH_ITERATOR_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_PITCH_ITERATOR_IMPL_HPP_INCLUDED

#include <mizuiro/image/detail/stacked_dim.hpp>
#include <mizuiro/image/dimension_impl.hpp>
#include <mizuiro/image/pitch_iterator_decl.hpp>
#include <mizuiro/image/iterator_position.hpp>
#include <mizuiro/detail/unlikely.hpp>
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
	root_data_(data_),
	pitch_(pitch_),
	line_advance_(0),
	position_(0),
	offset_(0),
	stacked_dim_(
		detail::stacked_dim(
			dim_
		)
	)
{}

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
typename mizuiro::image::pitch_iterator<Format, Constness>::difference_type
mizuiro::image::pitch_iterator<Format, Constness>::offset() const
{
	return offset_;
}

template<
	typename Format,
	typename Constness
>
typename mizuiro::image::pitch_iterator<Format, Constness>::pointer
mizuiro::image::pitch_iterator<Format, Constness>::data() const
{
	return root_data_ + position_;
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

	line_advance_ = -1;

	difference_type add = diff * Format::color_format::element_count;

	difference_type const diff_to_begin(
		offset_
	);

	for(
		size_type i = 0;
		i < pitch_type::static_size;
		++i
	)
		add += (
			(diff +
				diff_to_begin
				% stacked_dim_[i]
			) / stacked_dim_[i]
		) * pitch_[i];

	offset_ += diff;
	position_ += add;
}

template<
	typename Format,
	typename Constness
>
void
mizuiro::image::pitch_iterator<Format, Constness>::increment()
{
	if(
		MIZUIRO_DETAIL_UNLIKELY(
			line_advance_ == -1
		)
	)
		line_advance_ =
			iterator_position(
				*this
			)[0];

	++line_advance_;

	if(
		MIZUIRO_DETAIL_UNLIKELY(
			line_advance_
			>= static_cast<
				difference_type
			>(
				dim_[0]
			)
		)
	)
	{
		advance(1);
		line_advance_ = 0;
	}
	else
	{
		position_ += Format::color_format::element_count;
		++offset_;
	}
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
	return other.offset_ - offset_;
}

template<
	typename Format,
	typename Constness
>
typename mizuiro::image::pitch_iterator<Format, Constness>::reference
mizuiro::image::pitch_iterator<Format, Constness>::dereference() const
{
	return reference(
		data()
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
	return position_ == other.position_;
}

#endif
