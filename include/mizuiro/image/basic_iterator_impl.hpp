//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_BASIC_ITERATOR_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_BASIC_ITERATOR_IMPL_HPP_INCLUDED

#include <mizuiro/image/basic_iterator_decl.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <memory>
#include <utility>
#include <mizuiro/detail/external_end.hpp>


template<
	typename Impl
>
mizuiro::image::basic_iterator<
	Impl
>::basic_iterator(
	Impl const &_impl
)
:
	impl_{
		_impl
	}
{
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
>::data() const
{
	return
		impl_.data();
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
		impl_.dereference();
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
	impl_.increment();

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
		impl_.equal(
			_other.impl_
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
		std::addressof(
			this->operator*()
		);
}

/*
template<
	typename Impl
>
mizuiro::image::basic_iterator<
	Impl
>::basic_iterator()
:
	impl_{}
{
}*/

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
	impl_.decrement();

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
	impl_.advance(
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
		_other.impl_.distance_to(
			impl_
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
