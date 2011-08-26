//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_VIEW_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_VIEW_IMPL_HPP_INCLUDED

#include <mizuiro/image/view_decl.hpp>
#include <mizuiro/image/format_base_impl.hpp>
#include <mizuiro/image/iterator_impl.hpp>
#include <mizuiro/image/linear_iterator_impl.hpp>
#include <mizuiro/image/move_iterator.hpp>
#include <mizuiro/image/pitch_iterator_impl.hpp>
#include <mizuiro/image/range_impl.hpp>
#include <stdexcept>

template<
	typename Access,
	typename Format,
	typename Constness
>
mizuiro::image::view<Access, Format, Constness>::view(
	dim const &_size,
	pointer const _data,
	format_store_type const &_format
)
:
	format_base(
		_format
	),
	size_(
		_size
	),
	data_(
		_data
	),
	pitch_(
		pitch_type::null()
	)
{
}

template<
	typename Access,
	typename Format,
	typename Constness
>
mizuiro::image::view<Access, Format, Constness>::view(
	dim const &_size,
	pointer const _data,
	pitch_type const &_pitch,
	format_store_type const &_format
)
:
	format_base(
		_format
	),
	size_(
		_size
	),
	data_(
		_data
	),
	pitch_(
		_pitch
	)
{
}

template<
	typename Access,
	typename Format,
	typename Constness
>
mizuiro::image::view<Access, Format, Constness>::view(
	view const &_other
)
:
	format_base(
		_other.format_store()
	),
	size_(
		_other.size_
	),
	data_(
		_other.data_
	),
	pitch_(
		_other.pitch_
	)
{
}

template<
	typename Access,
	typename Format,
	typename Constness
>
template<
	typename OtherConstness
>
mizuiro::image::view<Access, Format, Constness>::view(
	image::view<
		Access,
		Format,
		OtherConstness
	> const &_other
)
:
	format_base(
		_other.format_store()
	),
	size_(
		_other.size()
	),
	data_(
		_other.data()
	),
	pitch_(
		_other.pitch()
	)
{
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename mizuiro::image::view<Access, Format, Constness>::dim const &
mizuiro::image::view<Access, Format, Constness>::size() const
{
	return size_;
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename mizuiro::image::view<Access, Format, Constness>::iterator const
mizuiro::image::view<Access, Format, Constness>::begin() const
{
	return
		is_linear()
		?
			iterator(
				linear_begin()
			)
		:
			iterator(
				pitch_begin()
			);
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename mizuiro::image::view<Access, Format, Constness>::iterator const
mizuiro::image::view<Access, Format, Constness>::end() const
{
	return
		begin()
		+
		static_cast<
			typename iterator::difference_type
		>(
			this->size().content()
		);
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename mizuiro::image::view<Access, Format, Constness>::range_type const
mizuiro::image::view<Access, Format, Constness>::range() const
{
	return
		is_linear()
		?
			range_type(
				linear_range(
					linear_begin(),
					linear_end()
				)
			)
		:
			range_type(
				pitch_range(
					pitch_begin(),
					pitch_end()
				)
			);
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename mizuiro::image::view<Access, Format, Constness>::reference
mizuiro::image::view<Access, Format, Constness>::operator[](
	dim const &_index
) const
{
	return
		*image::move_iterator(
			*this,
			_index
		);
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename mizuiro::image::view<Access, Format, Constness>::reference
mizuiro::image::view<Access, Format, Constness>::at(
	dim const &_index
) const
{
	for(
		size_type i = 0;
		i < dim::static_size;
		++i
	)
		// TODO: replace this with our own exception and add a better error message!
		if(
			_index[i] >= this->size()[i]
		)
			throw std::range_error("view::at out of range");

	return (*this)[_index];
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename mizuiro::image::view<Access, Format, Constness>::pointer
mizuiro::image::view<Access, Format, Constness>::data() const
{
	return data_;
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename mizuiro::image::view<Access, Format, Constness>::pitch_type const &
mizuiro::image::view<Access, Format, Constness>::pitch() const
{
	return pitch_;
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename mizuiro::image::view<Access, Format, Constness>::format_store_type const
mizuiro::image::view<Access, Format, Constness>::format_store() const
{
	return this->format_store_base();
}

template<
	typename Access,
	typename Format,
	typename Constness
>
bool
mizuiro::image::view<Access, Format, Constness>::is_linear() const
{
	return
		pitch_ == pitch_type::null()
		|| this->size().content() == 0;
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename mizuiro::image::view<Access, Format, Constness>::linear_iterator const
mizuiro::image::view<Access, Format, Constness>::linear_begin() const
{
	return
		linear_iterator(
			data_,
			this->format_store()
		);
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename mizuiro::image::view<Access, Format, Constness>::linear_iterator const
mizuiro::image::view<Access, Format, Constness>::linear_end() const
{
	return
		linear_begin()
		+
		static_cast<
			typename linear_iterator::difference_type
		>(
			this->size().content()
		);
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename mizuiro::image::view<Access, Format, Constness>::pitch_iterator const
mizuiro::image::view<Access, Format, Constness>::pitch_begin() const
{
	return
		pitch_iterator(
			this->size(),
			data_,
			pitch_,
			this->format_store()
		);
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename mizuiro::image::view<Access, Format, Constness>::pitch_iterator const
mizuiro::image::view<Access, Format, Constness>::pitch_end() const
{
	return
		pitch_begin()
		+
		static_cast<
			typename pitch_iterator::difference_type
		>(
			this->size().content()
		);
}

#endif
