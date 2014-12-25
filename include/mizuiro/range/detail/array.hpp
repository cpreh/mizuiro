//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_RANGE_DETAIL_ARRAY_HPP_INCLUDED
#define MIZUIRO_RANGE_DETAIL_ARRAY_HPP_INCLUDED

#include <mizuiro/detail/nonassignable.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <array>
#include <cstddef>
#include <type_traits>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace range
{
namespace detail
{

template<
	typename Array,
	std::size_t Index = 0u
>
class array
{
	MIZUIRO_DETAIL_NONASSIGNABLE(
		array
	);
public:
	typedef
	std::integral_constant<
		bool,
		Index
		==
		std::tuple_size<
			Array
		>::value
	>
	empty;

	explicit
	array(
		Array const &_array
	)
	:
		array_(
			_array
		)
	{
	}

	typename
	Array::value_type const &
	get() const
	{
		return
			array_[
				Index
			];
	}

	array<
		Array,
		Index + 1u
	>
	next() const
	{
		return
			array<
				Array,
				Index + 1u
			>(
				array_
			);
	}
private:
	Array const &array_;
};

}
}
}

#endif
