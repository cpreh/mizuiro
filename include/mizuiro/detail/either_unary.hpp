//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_EITHER_UNARY_HPP_INCLUDED
#define MIZUIRO_DETAIL_EITHER_UNARY_HPP_INCLUDED

#include <mizuiro/detail/either_impl.hpp>


namespace mizuiro
{
namespace detail
{

template<
	typename Left,
	typename Right,
	typename Op
>
typename
Op::result_type
either_unary(
	Op const &_op,
	mizuiro::detail::either<
		Left,
		Right
	> const &_either
)
{
	return
		_either.is_left()
		?
			_op(
				_either.left()
			)
		:
			_op(
				_either.right()
			)
		;
}

}
}

#endif
