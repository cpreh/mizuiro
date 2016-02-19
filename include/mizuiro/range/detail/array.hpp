//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_RANGE_DETAIL_ARRAY_HPP_INCLUDED
#define MIZUIRO_RANGE_DETAIL_ARRAY_HPP_INCLUDED

#include <mizuiro/detail/nonassignable.hpp>
#include <mizuiro/mpl/bool.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <array>
#include <cstddef>
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
	mizuiro::mpl::bool_<
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

	typedef
	typename
	Array::value_type
	head_type;

	typedef
	array<
		Array,
		Index + 1u
	>
	tail_type;

	head_type const &
	get() const
	{
		return
			array_[
				Index
			];
	}

	tail_type
	next() const
	{
		return
			tail_type(
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
