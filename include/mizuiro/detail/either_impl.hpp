//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_EITHER_IMPL_HPP_INCLUDED
#define MIZUIRO_DETAIL_EITHER_IMPL_HPP_INCLUDED

#include <mizuiro/detail/either_decl.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <type_traits>
#include <mizuiro/detail/external_end.hpp>


template<
	typename Left,
	typename Right
>
mizuiro::detail::either<
	Left,
	Right
>::either(
	Left const &_left
)
:
	left_(
		_left
	),
	is_left_{
		true
	}
{
}

template<
	typename Left,
	typename Right
>
mizuiro::detail::either<
	Left,
	Right
>::either(
	Right const &_right
)
:
	right_(
		_right
	),
	is_left_{
		false
	}
{
}

template<
	typename Left,
	typename Right
>
mizuiro::detail::either<
	Left,
	Right
>::either(
	either const &_other
)
noexcept
:
	is_left_{
		_other.is_left_
	}
{
	static_assert(
		std::is_nothrow_copy_constructible<
			Left
		>::value,
		"Left's copy constructor must not throw"
	);

	static_assert(
		std::is_nothrow_copy_constructible<
			Right
		>::value,
		"Right's copy constructor must not throw"
	);

	this->copy(
		_other
	);
}

template<
	typename Left,
	typename Right
>
mizuiro::detail::either<
	Left,
	Right
> &
mizuiro::detail::either<
	Left,
	Right
>::operator=(
	either const &_other
)
{
	static_assert(
		std::is_nothrow_copy_constructible<
			Left
		>::value,
		"Left's copy constructor must not throw"
	);

	static_assert(
		std::is_nothrow_copy_constructible<
			Right
		>::value,
		"Right's copy constructor must not throw"
	);

	if(
		is_left_
		&&
		_other.is_left_
	)
		left_ = _other.left_;
	else if(
		!is_left_
		&&
		!_other.is_left_
	)
		right_ = _other.right_;
	else
	{
		this->destroy();

		this->copy(
			_other
		);

		is_left_ =
			_other.is_left_;
	}

	return
		*this;
}

template<
	typename Left,
	typename Right
>
mizuiro::detail::either<
	Left,
	Right
>::~either()
{
	this->destroy();
}

template<
	typename Left,
	typename Right
>
bool
mizuiro::detail::either<
	Left,
	Right
>::is_left() const
{
	return
		is_left_;
}

template<
	typename Left,
	typename Right
>
Left const &
mizuiro::detail::either<
	Left,
	Right
>::left() const
{
	return
		left_;
}

template<
	typename Left,
	typename Right
>
Right const &
mizuiro::detail::either<
	Left,
	Right
>::right() const
{
	return
		right_;
}

template<
	typename Left,
	typename Right
>
void
mizuiro::detail::either<
	Left,
	Right
>::copy(
	either const &_other
)
{
	if(
		is_left_
	)
		new (
			&left_
		)
		Left(
			_other.left_
		);
	else
		new (
			&right_
		)
		Right(
			_other.right_
		);
}

template<
	typename Left,
	typename Right
>
void
mizuiro::detail::either<
	Left,
	Right
>::destroy()
{
	if(
		is_left_
	)
		left_.~Left();
	else
		right_.~Right();
}

#endif
