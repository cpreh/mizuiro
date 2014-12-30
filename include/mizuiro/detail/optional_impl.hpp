//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_OPTIONAL_IMPL_HPP_INCLUDED
#define MIZUIRO_DETAIL_OPTIONAL_IMPL_HPP_INCLUDED

#include <mizuiro/detail/either_impl.hpp>
#include <mizuiro/detail/nothing.hpp>
#include <mizuiro/detail/optional_decl.hpp>


template<
	typename Type
>
mizuiro::detail::optional<
	Type
>::optional(
	mizuiro::detail::nothing const _nothing
)
:
	impl_{
		_nothing
	}
{
}

template<
	typename Type
>
mizuiro::detail::optional<
	Type
>::optional(
	Type const &_value
)
:
	impl_{
		_value
	}
{
}

template<
	typename Type
>
mizuiro::detail::optional<
	Type
>::optional(
	optional const &
) noexcept
= default;

template<
	typename Type
>
mizuiro::detail::optional<
	Type
> &
mizuiro::detail::optional<
	Type
>::operator=(
	optional const &
)
= default;

template<
	typename Type
>
mizuiro::detail::optional<
	Type
>::~optional()
= default;

template<
	typename Type
>
bool
mizuiro::detail::optional<
	Type
>::has_value() const
{
	return
		impl_.is_left();
}

template<
	typename Type
>
Type const &
mizuiro::detail::optional<
	Type
>::get() const
{
	return
		impl_.left();
}

#endif
