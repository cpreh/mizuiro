//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_LINEAR_VIEW_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_LINEAR_VIEW_IMPL_HPP_INCLUDED

#include <mizuiro/image/dimension_content.hpp>
#include <mizuiro/image/dimension_null.hpp>
#include <mizuiro/image/linear_iterator_impl.hpp>
#include <mizuiro/image/linear_view_decl.hpp>
#include <mizuiro/image/move_iterator.hpp>
#include <mizuiro/image/format/base_impl.hpp>


template<
	typename Access,
	typename Format,
	typename Constness
>
mizuiro::image::linear_view<
	Access,
	Format,
	Constness
>::linear_view(
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
	)
{
}

template<
	typename Access,
	typename Format,
	typename Constness
>
mizuiro::image::linear_view<
	Access,
	Format,
	Constness
>::linear_view(
	linear_view const &_other
) noexcept
:
	format_base(
		_other.format_store()
	),
	size_(
		_other.size()
	),
	data_(
		_other.data()
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
mizuiro::image::linear_view<
	Access,
	Format,
	Constness
>::linear_view(
	mizuiro::image::linear_view<
		access,
		format,
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
	)
{
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename
mizuiro::image::linear_view<
	Access,
	Format,
	Constness
>::dim const &
mizuiro::image::linear_view<
	Access,
	Format,
	Constness
>::size() const
{
	return
		size_;
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename
mizuiro::image::linear_view<
	Access,
	Format,
	Constness
>::pitch_type
mizuiro::image::linear_view<
	Access,
	Format,
	Constness
>::pitch() const
{
	return
		mizuiro::image::dimension_null<
			pitch_type
		>();
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename
mizuiro::image::linear_view<
	Access,
	Format,
	Constness
>::iterator
mizuiro::image::linear_view<
	Access,
	Format,
	Constness
>::begin() const
{
	return
		iterator(
			data_,
			this->format_store()
		);
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename
mizuiro::image::linear_view<
	Access,
	Format,
	Constness
>::iterator
mizuiro::image::linear_view<
	Access,
	Format,
	Constness
>::end() const
{
	return
		this->begin()
		+
		static_cast<
			typename
			iterator::difference_type
		>(
			mizuiro::image::dimension_content(
				this->size()
			)
		);
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename
mizuiro::image::linear_view<
	Access,
	Format,
	Constness
>::reference
mizuiro::image::linear_view<
	Access,
	Format,
	Constness
>::operator[](
	dim const &_index
) const
{
	return
		*mizuiro::image::move_iterator(
			*this,
			_index
		);
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename
mizuiro::image::linear_view<
	Access,
	Format,
	Constness
>::pointer
mizuiro::image::linear_view<
	Access,
	Format,
	Constness
>::data() const
{
	return
		data_;
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename
mizuiro::image::linear_view<
	Access,
	Format,
	Constness
>::format_store_type
mizuiro::image::linear_view<
	Access,
	Format,
	Constness
>::format_store() const
{
	return
		this->format_store_base();
}

#endif
