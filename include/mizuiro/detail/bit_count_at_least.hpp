//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_BIT_COUNT_AT_LEAST_HPP_INCLUDED
#define MIZUIRO_DETAIL_BIT_COUNT_AT_LEAST_HPP_INCLUDED

#include <mizuiro/detail/bit_count.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/types/bool.hpp>
#include <fcppt/config/external_end.hpp>


namespace mizuiro
{
namespace detail
{

template<
	typename Bits,
	typename IntType
>
using
bit_count_at_least
=
brigand::bool_<
	mizuiro::detail::bit_count<
		IntType
	>::value
	>=
	Bits::value
>;

}
}

#endif
