//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_BASIC_ITERATOR_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_BASIC_ITERATOR_IMPL_HPP_INCLUDED

#include <mizuiro/image/basic_iterator_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <memory>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Impl
>
typename
mizuiro::image::basic_iterator<
	Impl
>::pointer
mizuiro::image::basic_iterator<
	Impl
>::data() const
{
	return
		Impl::data();
}

template<
	typename Impl
>
mizuiro::image::basic_iterator<
	Impl
>::basic_iterator(
	basic_iterator const &
) noexcept
= default;

template<
	typename Impl
>
mizuiro::image::basic_iterator<
	Impl
>::basic_iterator(
	basic_iterator &&
) noexcept
= default;

template<
	typename Impl
>
mizuiro::image::basic_iterator<
	Impl
> &
mizuiro::image::basic_iterator<
	Impl
>::operator=(
	basic_iterator const &
)
= default;

template<
	typename Impl
>
mizuiro::image::basic_iterator<
	Impl
> &
mizuiro::image::basic_iterator<
	Impl
>::operator=(
	basic_iterator &&
)
= default;

template<
	typename Impl
>
mizuiro::image::basic_iterator<
	Impl
>::~basic_iterator()
= default;

template<
	typename Impl
>
typename
mizuiro::image::basic_iterator<
	Impl
>::reference
mizuiro::image::basic_iterator<
	Impl
>::operator*() const
{
	return
		this->dereference();
}

template<
	typename Impl
>
mizuiro::image::basic_iterator<
	Impl
> &
mizuiro::image::basic_iterator<
	Impl
>::operator++()
{
	this->increment();

	return
		*this;
}

template<
	typename Impl
>
bool
mizuiro::image::basic_iterator<
	Impl
>::operator==(
	basic_iterator const &_other
) const
{
	return
		this->equal(
			_other
		);
}

template<
	typename Impl
>
typename
mizuiro::image::basic_iterator<
	Impl
>::pointer
mizuiro::image::basic_iterator<
	Impl
>::operator->() const
{
	return
		this->data();
}

template<
	typename Impl
>
mizuiro::image::basic_iterator<
	Impl
> &
mizuiro::image::basic_iterator<
	Impl
>::operator--()
{
	this->decrement();

	return
		*this;
}

template<
	typename Impl
>
mizuiro::image::basic_iterator<
	Impl
> &
mizuiro::image::basic_iterator<
	Impl
>::operator+=(
	difference_type const _diff
)
{
	this->advance(
		_diff
	);

	return
		*this;
}

template<
	typename Impl
>
typename
mizuiro::image::basic_iterator<
	Impl
>::difference_type
mizuiro::image::basic_iterator<
	Impl
>::operator-(
	basic_iterator const &_other
) const
{
	return
		_other.distance_to(
			*this
		);
}

template<
	typename Impl
>
typename
mizuiro::image::basic_iterator<
	Impl
>::reference
mizuiro::image::basic_iterator<
	Impl
>::operator[](
	difference_type const _diff
) const
{
	return
		*(
			*this
			+
			_diff
		);
}

template<
	typename Impl
>
void
mizuiro::image::swap(
	mizuiro::image::basic_iterator<
		Impl
	> &_left,
	mizuiro::image::basic_iterator<
		Impl
	> &_right
)
{
	std::swap(
		_left,
		_right
	);
}

template<
	typename Impl
>
bool
mizuiro::image::operator!=(
	mizuiro::image::basic_iterator<
		Impl
	> const &_left,
	mizuiro::image::basic_iterator<
		Impl
	> const &_right
)
{
	return
		!(
			_left
			==
			_right
		);
}

template<
	typename Impl
>
mizuiro::image::basic_iterator<
	Impl
>
mizuiro::image::operator++(
	mizuiro::image::basic_iterator<
		Impl
	> &_it,
	int
)
{
	mizuiro::image::basic_iterator<
		Impl
	> temp{
		_it
	};

	++_it;

	return
		temp;
}

template<
	typename Impl
>
mizuiro::image::basic_iterator<
	Impl
>
mizuiro::image::operator--(
	mizuiro::image::basic_iterator<
		Impl
	> &_it,
	int
)
{
	mizuiro::image::basic_iterator<
		Impl
	> temp{
		_it
	};

	--_it;

	return
		temp;
}

template<
	typename Impl
>
mizuiro::image::basic_iterator<
	Impl
>
mizuiro::image::operator+(
	mizuiro::image::basic_iterator<
		Impl
	> _it,
	typename
	mizuiro::image::basic_iterator<
		Impl
	>::difference_type const _diff
)
{
	return
		_it
		+=
		_diff;
}

template<
	typename Impl
>
mizuiro::image::basic_iterator<
	Impl
>
mizuiro::image::operator+(
	typename
	mizuiro::image::basic_iterator<
		Impl
	>::difference_type const _diff,
	mizuiro::image::basic_iterator<
		Impl
	> const &_it
)
{
	return
		_it
		+
		_diff;
}

template<
	typename Impl
>
mizuiro::image::basic_iterator<
	Impl
> &
mizuiro::image::operator-=(
	mizuiro::image::basic_iterator<
		Impl
	> &_it,
	typename
	mizuiro::image::basic_iterator<
		Impl
	>::difference_type const _diff
)
{
	return
		_it
		+=
		-_diff;
}

template<
	typename Impl
>
mizuiro::image::basic_iterator<
	Impl
>
mizuiro::image::operator-(
	mizuiro::image::basic_iterator<
		Impl
	> _it,
	typename
	mizuiro::image::basic_iterator<
		Impl
	>::difference_type const _diff
)
{
	return
		_it
		-=
		_diff;
}

template<
	typename Impl
>
bool
mizuiro::image::operator<(
	mizuiro::image::basic_iterator<
		Impl
	> const &_left,
	mizuiro::image::basic_iterator<
		Impl
	> const &_right
)
{
	return
		_right
		-
		_left
		>
		0;
}

template<
	typename Impl
>
bool
mizuiro::image::operator>(
	mizuiro::image::basic_iterator<
		Impl
	> const &_left,
	mizuiro::image::basic_iterator<
		Impl
	> const &_right
)
{
	return
		_right
		<
		_left;
}

template<
	typename Impl
>
bool
mizuiro::image::operator>=(
	mizuiro::image::basic_iterator<
		Impl
	> const &_left,
	mizuiro::image::basic_iterator<
		Impl
	> const &_right
)
{
	return
		!(
			_left
			<
			_right
		);
}

template<
	typename Impl
>
bool
mizuiro::image::operator<=(
	mizuiro::image::basic_iterator<
		Impl
	> const &_left,
	mizuiro::image::basic_iterator<
		Impl
	> const &_right
)
{
	return
		!(
			_left
			>
			_right
		);
}

#endif
