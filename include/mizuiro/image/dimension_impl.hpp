//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_DIMENSION_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_DIMENSION_IMPL_HPP_INCLUDED

#include <mizuiro/image/dimension_decl.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <ostream>
#include <mizuiro/detail/external_end.hpp>


template<
	mizuiro::size_type Dim,
	typename ValueType
>
mizuiro::image::dimension<
	Dim,
	ValueType
>::dimension()
:
	data_()
{
}

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
bool
mizuiro::image::dimension<
	Dim,
	ValueType
>::empty() const
{
	return
		false;
}

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
	return data_.begin();
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
>::size_type
mizuiro::image::dimension<
	Dim,
	ValueType
>::size() const
{
	return
		data_.size();
}

template<
	mizuiro::size_type Dim,
	typename ValueType
>
typename
mizuiro::image::dimension<
	Dim,
	ValueType
>::size_type
mizuiro::image::dimension<
	Dim,
	ValueType
>::content() const
{
	return
		std::accumulate(
			begin(),
			end(),
			static_cast<
				size_type
			>(
				1
			),
			std::multiplies<
				value_type
			>()
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

template<
	mizuiro::size_type Dim,
	typename ValueType
>
void
mizuiro::image::dimension<
	Dim,
	ValueType
>::swap(
	dimension &_other
)
{
	data_.swap(
		_other.data_
	);
}

template<
	mizuiro::size_type Dim,
	typename ValueType
>
mizuiro::image::dimension<
	Dim,
	ValueType
> const
mizuiro::image::dimension<
	Dim,
	ValueType
>::null()
{
	dimension ret;

	for(
		auto &elem
		:
		ret
	)
		elem = 0;

	return ret;
}

template<
	mizuiro::size_type Dim,
	typename ValueType
>
void
mizuiro::image::swap(
	mizuiro::image::dimension<
		Dim,
		ValueType
	> &_a,
	mizuiro::image::dimension<
		Dim,
		ValueType
	> &_b
)
{
	_a.swap(
		_b
	);
}

template<
	mizuiro::size_type Dim,
	typename ValueType
>
mizuiro::image::dimension<
	Dim,
	ValueType
> const
	mizuiro::image::operator+(
		mizuiro::image::dimension<
		Dim,
		ValueType
	> const &_a,
	mizuiro::image::dimension<
		Dim,
		ValueType
	> const &_b
)
{
	typedef mizuiro::image::dimension<
		Dim,
		ValueType
	> dim;

	dim ret;

	for(
		typename dim::size_type i = 0;
		i < dim::static_size;
		++i
	)
		ret[i] = _a[i] + _b[i];

	return ret;
}

template<
	mizuiro::size_type Dim,
	typename ValueType
>
bool
mizuiro::image::operator==(
	mizuiro::image::dimension<
		Dim,
		ValueType
	> const &_a,
	mizuiro::image::dimension<
		Dim,
		ValueType
	> const &_b
)
{
	return
		std::equal(
			_a.begin(),
			_a.end(),
			_b.begin()
		);
}

template<
	mizuiro::size_type Dim,
	typename ValueType
>
bool
mizuiro::image::operator!=(
	mizuiro::image::dimension<
		Dim,
		ValueType
	> const &_a,
	mizuiro::image::dimension<
		Dim,
		ValueType
	> const &_b
)
{
	return !(_a == _b);
}

template<
	mizuiro::size_type Dim,
	typename ValueType,
	typename Ch,
	typename Traits
>
std::basic_ostream<
	Ch,
	Traits
> &
mizuiro::image::operator<<(
	std::basic_ostream<
		Ch,
		Traits
	> &_stream,
	mizuiro::image::dimension<
		Dim,
		ValueType
	> const &_dim
)
{
	typedef
	mizuiro::image::dimension<
		Dim,
		ValueType
	> dim;

	_stream << _stream.widen('(');

	for(
		typename dim::size_type i = 0;
		i < dim::static_size;
		++i
	)
	{
		_stream << _dim[i];

		if(
			i != dim::static_size - 1
		)
			_stream << _stream.widen(',');
	}

	_stream << _stream.widen(')');

	return _stream;
}

#endif
