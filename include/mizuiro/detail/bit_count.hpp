//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_BIT_COUNT_HPP_INCLUDED
#define MIZUIRO_DETAIL_BIT_COUNT_HPP_INCLUDED

#include <mizuiro/integral_size.hpp>
#include <mizuiro/detail/static_assert_statement.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/type_traits/is_unsigned.hpp>
#include <limits>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace detail
{

MIZUIRO_DETAIL_IGNORE_EFFCPP

template<
	typename IntType
>
struct bit_count
:
mizuiro::integral_size<
	std::numeric_limits<
		IntType
	>::digits
>
{
	MIZUIRO_DETAIL_STATIC_ASSERT_STATEMENT(
		boost::is_unsigned<
			IntType
		>::value
	);
};

MIZUIRO_DETAIL_POP_WARNING

}
}

#endif
