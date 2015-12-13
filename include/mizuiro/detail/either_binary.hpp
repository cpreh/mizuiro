//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_EITHER_BINARY_HPP_INCLUDED
#define MIZUIRO_DETAIL_EITHER_BINARY_HPP_INCLUDED

#include <mizuiro/detail/either_impl.hpp>


namespace mizuiro
{
namespace detail
{

template<
	typename Left1,
	typename Right1,
	typename Left2,
	typename Right2,
	typename Op
>
decltype(
	auto
)
either_binary(
	Op const &_op,
	mizuiro::detail::either<
		Left1,
		Right1
	> const &_either1,
	mizuiro::detail::either<
		Left2,
		Right2
	> const &_either2
)
{
	return
		_either1.is_left()
		?
			_either2.is_left()
			?
				_op(
					_either1.left(),
					_either2.left()
				)
			:
				_op(
					_either1.left(),
					_either2.right()
				)
		:
			_either2.is_left()
			?
				_op(
					_either1.right(),
					_either2.left()
				)
			:
				_op(
					_either1.right(),
					_either2.right()
				)
		;
}

}
}

#endif
