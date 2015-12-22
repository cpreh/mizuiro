//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_DIMENSION_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_DIMENSION_IMPL_HPP_INCLUDED

#include <mizuiro/no_init_fwd.hpp>
#include <mizuiro/size_type.hpp>
#include <mizuiro/image/dimension_decl.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <iterator>
#include <mizuiro/detail/external_end.hpp>


MIZUIRO_DETAIL_IGNORE_EFFCPP

template<
	mizuiro::size_type Dim,
	typename ValueType
>
mizuiro::image::dimension<
	Dim,
	ValueType
>::dimension(
	mizuiro::no_init const &
)
{
}

template<
	mizuiro::size_type Dim,
	typename ValueType
>
mizuiro::image::dimension<
	Dim,
	ValueType
>::dimension(
	mizuiro::no_init &&
)
{
}

MIZUIRO_DETAIL_POP_WARNING

template<
	mizuiro::size_type Dim,
	typename ValueType
>
template<
	typename ...Args
>
mizuiro::image::dimension<
	Dim,
	ValueType
>::dimension(
	Args &&... _args
)
:
	data_{{
		std::forward<
			Args
		>(
			_args
		)...
	}}
{
	static_assert(
		sizeof...(
			Args
		)
		==
		Dim,
		"Invalid parameter count"
	);
}

template<
	mizuiro::size_type Dim,
	typename ValueType
>
mizuiro::image::dimension<
	Dim,
	ValueType
>::dimension(
	dimension const &
) noexcept
= default;

template<
	mizuiro::size_type Dim,
	typename ValueType
>
mizuiro::image::dimension<
	Dim,
	ValueType
>::dimension(
	dimension &&
)
= default;

template<
	mizuiro::size_type Dim,
	typename ValueType
>
mizuiro::image::dimension<
	Dim,
	ValueType
>::dimension(
	dimension const &&_other
)
:
	data_(
		_other.data_
	)
{
}

template<
	mizuiro::size_type Dim,
	typename ValueType
>
mizuiro::image::dimension<
	Dim,
	ValueType
> &
mizuiro::image::dimension<
	Dim,
	ValueType
>::operator=(
	dimension const &
)
= default;

template<
	mizuiro::size_type Dim,
	typename ValueType
>
mizuiro::image::dimension<
	Dim,
	ValueType
> &
mizuiro::image::dimension<
	Dim,
	ValueType
>::operator=(
	dimension &&
)
= default;

template<
	mizuiro::size_type Dim,
	typename ValueType
>
mizuiro::image::dimension<
	Dim,
	ValueType
>::~dimension()
= default;

template<
	mizuiro::size_type Dim,
	typename ValueType
>
typename mizuiro::image::dimension<
	Dim,
	ValueType
>::iterator
mizuiro::image::dimension<
	Dim,
	ValueType
>::begin()
{
	return
		data_.begin();
}

template<
	mizuiro::size_type Dim,
	typename ValueType
>
typename
mizuiro::image::dimension<
	Dim,
	ValueType
>::iterator
mizuiro::image::dimension<
	Dim,
	ValueType
>::end()
{
	return
		data_.end();
}

template<
	mizuiro::size_type Dim,
	typename ValueType
>
typename
mizuiro::image::dimension<
	Dim,
	ValueType
>::const_iterator
mizuiro::image::dimension<
	Dim,
	ValueType
>::begin() const
{
	return
		data_.begin();
}

template<
	mizuiro::size_type Dim,
	typename ValueType
>
typename
mizuiro::image::dimension<
	Dim,
	ValueType
>::const_iterator
mizuiro::image::dimension<
	Dim,
	ValueType
>::end() const
{
	return
		data_.end();
}

template<
	mizuiro::size_type Dim,
	typename ValueType
>
typename
mizuiro::image::dimension<
	Dim,
	ValueType
>::reference
mizuiro::image::dimension<
	Dim,
	ValueType
>::operator[](
	size_type const _index
)
{
	return
		data_[
			_index
		];
}

template<
	mizuiro::size_type Dim,
	typename ValueType
>
typename
mizuiro::image::dimension<
	Dim,
	ValueType
>::const_reference
mizuiro::image::dimension<
	Dim,
	ValueType
>::operator[](
	size_type const _index
) const
{
	return
		data_[
			_index
		];
}

template<
	mizuiro::size_type Dim,
	typename ValueType
>
template<
	typename
	mizuiro::image::dimension<
		Dim,
		ValueType
	>::size_type Index
>
typename
mizuiro::image::dimension<
	Dim,
	ValueType
>::reference
mizuiro::image::dimension<
	Dim,
	ValueType
>::at_c()
{
	static_assert(
		Index < Dim,
		"Index out of range"
	);

	return
		(*this)[
			Index
		];
}

template<
	mizuiro::size_type Dim,
	typename ValueType
>
template<
	typename
	mizuiro::image::dimension<
		Dim,
		ValueType
	>::size_type Index
>
typename
mizuiro::image::dimension<
	Dim,
	ValueType
>::const_reference
mizuiro::image::dimension<
	Dim,
	ValueType
>::at_c() const
{
	static_assert(
		Index < Dim,
		"Index out of range"
	);

	return
		(*this)[
			Index
		];
}

template<
	mizuiro::size_type Dim,
	typename ValueType
>
typename
mizuiro::image::dimension<
	Dim,
	ValueType
>::reference
mizuiro::image::dimension<
	Dim,
	ValueType
>::back()
{
	return
		*std::prev(
			this->end()
		);
}

template<
	mizuiro::size_type Dim,
	typename ValueType
>
typename
mizuiro::image::dimension<
	Dim,
	ValueType
>::const_reference
mizuiro::image::dimension<
	Dim,
	ValueType
>::back() const
{
	return
		*std::prev(
			this->end()
		);
}

#endif
