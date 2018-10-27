//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_VIEW_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_VIEW_IMPL_HPP_INCLUDED

#include <mizuiro/image/dimension_comparison.hpp>
#include <mizuiro/image/dimension_impl.hpp>
#include <mizuiro/image/dimension_null.hpp>
#include <mizuiro/image/iterator_impl.hpp>
#include <mizuiro/image/linear_view_impl.hpp>
#include <mizuiro/image/make_const_view.hpp>
#include <mizuiro/image/move_iterator.hpp>
#include <mizuiro/image/pitch_view_impl.hpp>
#include <mizuiro/image/view_decl.hpp>
#include <fcppt/variant/apply.hpp>


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
		mizuiro::image::dimension_null<
			pitch_type
		>()
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
		fcppt::variant::apply(
			[](
				auto const &_view
			)
			{
				return
					view_variant(
						mizuiro::image::make_const_view(
							_view
						)
					);
			},
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
>::dim
mizuiro::image::view<
	Access,
	Format,
	Constness
>::size() const
{
	return
		fcppt::variant::apply(
			[](
				auto const &_view
			)
			{
				return
					_view.size();
			},
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
>::pitch_type
mizuiro::image::view<
	Access,
	Format,
	Constness
>::pitch() const
{
	return
		fcppt::variant::apply(
			[](
				auto const &_view
			)
			{
				return
					_view.pitch();
			},
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
>::iterator
mizuiro::image::view<
	Access,
	Format,
	Constness
>::begin() const
{
	return
		fcppt::variant::apply(
			[](
				auto const &_view
			)
			{
				return
					iterator(
						typename
						iterator::impl::internal_type{
							_view.begin()
						}
					);
			},
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
>::iterator
mizuiro::image::view<
	Access,
	Format,
	Constness
>::end() const
{
	return
		fcppt::variant::apply(
			[](
				auto const &_view
			)
			{
				return
					iterator(
						typename
						iterator::impl::internal_type{
							_view.end()
						}
					);
			},
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
		fcppt::variant::apply(
			[](
				auto const &_view
			)
			{
				return
					_view.data();
			},
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
>::format_store_type
mizuiro::image::view<
	Access,
	Format,
	Constness
>::format_store() const
{
	return
		fcppt::variant::apply(
			[](
				auto const &_view
			)
			{
				return
					_view.format_store();
			},
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
