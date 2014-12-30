//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_VIEW_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_VIEW_IMPL_HPP_INCLUDED

#include <mizuiro/detail/either_impl.hpp>
#include <mizuiro/detail/either_unary.hpp>
#include <mizuiro/image/dimension_impl.hpp>
#include <mizuiro/image/iterator_impl.hpp>
#include <mizuiro/image/linear_view_impl.hpp>
#include <mizuiro/image/move_iterator.hpp>
#include <mizuiro/image/pitch_view_impl.hpp>
#include <mizuiro/image/view_decl.hpp>
#include <mizuiro/image/detail/view_begin.hpp>
#include <mizuiro/image/detail/view_convert_const.hpp>
#include <mizuiro/image/detail/view_data.hpp>
#include <mizuiro/image/detail/view_end.hpp>
#include <mizuiro/image/detail/view_format_store.hpp>
#include <mizuiro/image/detail/view_pitch.hpp>
#include <mizuiro/image/detail/view_size.hpp>


template<
	typename Access,
	typename Format,
	typename Constness
>
mizuiro::image::view<
	Access,
	Format,
	Constness
>::view(
	linear_view const &_view
)
:
	impl_(
		_view
	)
{
}

template<
	typename Access,
	typename Format,
	typename Constness
>
mizuiro::image::view<
	Access,
	Format,
	Constness
>::view(
	pitch_view const &_view
)
:
	impl_(
		_view
	)
{
}

template<
	typename Access,
	typename Format,
	typename Constness
>
mizuiro::image::view<
	Access,
	Format,
	Constness
>::view(
	dim const &_size,
	pointer const _data,
	pitch_type const &_pitch,
	format_store_type const &_format
)
:
	impl_(
		_pitch
		==
		pitch_type::null()
		?
			view_variant(
				linear_view(
					_size,
					_data,
					_format
				)
			)
		:
			view_variant(
				pitch_view(
					_size,
					_data,
					_pitch,
					_format
				)
			)
	)
{
}

template<
	typename Access,
	typename Format,
	typename Constness
>
mizuiro::image::view<
	Access,
	Format,
	Constness
>::view(
	dim const &_size,
	pointer const _data,
	format_store_type const &_format
)
:
	impl_(
		linear_view(
			_size,
			_data,
			_format
		)
	)
{
}

template<
	typename Access,
	typename Format,
	typename Constness
>
mizuiro::image::view<
	Access,
	Format,
	Constness
>::view(
	view const &_other
) noexcept
= default;

template<
	typename Access,
	typename Format,
	typename Constness
>
template<
	typename OtherConstness
>
mizuiro::image::view<
	Access,
	Format,
	Constness
>::view(
	mizuiro::image::view<
		Access,
		Format,
		OtherConstness
	> const &_other
)
:
	impl_(
		mizuiro::detail::either_unary(
			mizuiro::image::detail::view_convert_const<
				view_variant
			>(),
			_other.impl()
		)
	)
{
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename mizuiro::image::view<
	Access,
	Format,
	Constness
>::dim const
mizuiro::image::view<
	Access,
	Format,
	Constness
>::size() const
{
	return
		mizuiro::detail::either_unary(
			mizuiro::image::detail::view_size<
				dim
			>(),
			impl_
		);
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename mizuiro::image::view<
	Access,
	Format,
	Constness
>::pitch_type const
mizuiro::image::view<
	Access,
	Format,
	Constness
>::pitch() const
{
	return
		mizuiro::detail::either_unary(
			mizuiro::image::detail::view_pitch<
				pitch_type
			>(),
			impl_
		);
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename mizuiro::image::view<
	Access,
	Format,
	Constness
>::iterator const
mizuiro::image::view<
	Access,
	Format,
	Constness
>::begin() const
{
	return
		mizuiro::detail::either_unary(
			mizuiro::image::detail::view_begin<
				iterator
			>(),
			impl_
		);
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename mizuiro::image::view<
	Access,
	Format,
	Constness
>::iterator const
mizuiro::image::view<
	Access,
	Format,
	Constness
>::end() const
{
	return
		mizuiro::detail::either_unary(
			mizuiro::image::detail::view_end<
				iterator
			>(),
			impl_
		);
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename mizuiro::image::view<
	Access,
	Format,
	Constness
>::reference
mizuiro::image::view<
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
typename mizuiro::image::view<
	Access,
	Format,
	Constness
>::pointer
mizuiro::image::view<
	Access,
	Format,
	Constness
>::data() const
{
	return
		mizuiro::detail::either_unary(
			mizuiro::image::detail::view_data<
				pointer
			>(),
			impl_
		);
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename mizuiro::image::view<
	Access,
	Format,
	Constness
>::format_store_type const
mizuiro::image::view<
	Access,
	Format,
	Constness
>::format_store() const
{
	return
		mizuiro::detail::either_unary(
			mizuiro::image::detail::view_format_store<
				format_store_type
			>(),
			impl_
		);
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename mizuiro::image::view<
	Access,
	Format,
	Constness
>::view_variant const &
mizuiro::image::view<
	Access,
	Format,
	Constness
>::impl() const
{
	return
		impl_;
}

#endif
