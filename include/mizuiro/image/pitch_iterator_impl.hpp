//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_PITCH_ITERATOR_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_PITCH_ITERATOR_IMPL_HPP_INCLUDED

#include <mizuiro/image/detail/stacked_dim.hpp>
#include <mizuiro/image/dimension_impl.hpp>
#include <mizuiro/image/pitch_iterator_decl.hpp>
#include <mizuiro/image/iterator_position.hpp>
#include <mizuiro/image/underlying_data_pointer.hpp>
#include <mizuiro/access/color_pointer.hpp>
#include <mizuiro/detail/unlikely.hpp>
#include <cassert>

template<
	typename Access,
	typename Format,
	typename Constness
>
mizuiro::image::pitch_iterator<Access, Format, Constness>::pitch_iterator(
	dim_type const &_dim,
	pointer const _data,
	pitch_type const &_pitch
)
:
	dim_(_dim),
	root_data_(_data),
	pitch_(_pitch),
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
	typename Access,
	typename Format,
	typename Constness
>
typename mizuiro::image::pitch_iterator<Access, Format, Constness>::dim_type const &
mizuiro::image::pitch_iterator<Access, Format, Constness>::dim() const
{
	return dim_;
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename mizuiro::image::pitch_iterator<Access, Format, Constness>::difference_type
mizuiro::image::pitch_iterator<Access, Format, Constness>::offset() const
{
	return offset_;
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename mizuiro::image::pitch_iterator<Access, Format, Constness>::pointer
mizuiro::image::pitch_iterator<Access, Format, Constness>::data() const
{
	return root_data_ + position_;
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename mizuiro::image::pitch_iterator<Access, Format, Constness>::pointer
mizuiro::image::pitch_iterator<Access, Format, Constness>::root_data() const
{
	return root_data_;
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename mizuiro::image::pitch_iterator<Access, Format, Constness>::pitch_type const &
mizuiro::image::pitch_iterator<Access, Format, Constness>::pitch() const
{
	return pitch_;
}

template<
	typename Access,
	typename Format,
	typename Constness
>
void
mizuiro::image::pitch_iterator<Access, Format, Constness>::advance(
	difference_type const _diff
)
{
	assert(dim_.content());

	line_advance_ = -1;

	if(
		_diff < 0
	)
	{
		*this =
			pitch_iterator(
				dim_,
				root_data_,
				pitch_
			) += (offset_ + _diff);
		return;
	}

	difference_type add = _diff * Format::color_format::element_count;

	for(
		size_type i = 0;
		i < pitch_type::static_size;
		++i
	)
		add += (
			(_diff +
				offset_
				% stacked_dim_[i]
			) / stacked_dim_[i]
		) * pitch_[i];

	offset_ += _diff;

	position_ += add;
}

template<
	typename Access,
	typename Format,
	typename Constness
>
void
mizuiro::image::pitch_iterator<Access, Format, Constness>::increment()
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
	typename Access,
	typename Format,
	typename Constness
>
void
mizuiro::image::pitch_iterator<Access, Format, Constness>::decrement()
{
	advance(-1);
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename mizuiro::image::pitch_iterator<Access, Format, Constness>::difference_type
mizuiro::image::pitch_iterator<Access, Format, Constness>::distance_to(
	pitch_iterator const &other
) const
{
	return other.offset_ - offset_;
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename mizuiro::image::pitch_iterator<Access, Format, Constness>::reference
mizuiro::image::pitch_iterator<Access, Format, Constness>::dereference() const
{
	return
		reference(
			underlying_data_pointer(
				*this
			)
		);
}

template<
	typename Access,
	typename Format,
	typename Constness
>
bool
mizuiro::image::pitch_iterator<Access, Format, Constness>::equal(
	pitch_iterator const &other
) const
{
	return position_ == other.position_;
}

#endif
