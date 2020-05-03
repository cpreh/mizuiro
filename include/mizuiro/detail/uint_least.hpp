//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_UINT_LEAST_HPP_INCLUDED
#define MIZUIRO_DETAIL_UINT_LEAST_HPP_INCLUDED

#include <mizuiro/detail/bit_count_at_least.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <fcppt/config/external_end.hpp>


namespace mizuiro
{
namespace detail
{

template<
	typename Bits
>
using uint_least
=
metal::front<
	metal::copy_if<
		metal::list<
			unsigned char,
			unsigned short, // NOLINT(google-runtime-int)
			unsigned int,
			unsigned long, // NOLINT(google-runtime-int)
			unsigned long long // NOLINT(google-runtime-int)
		>,
		metal::bind<
			metal::trait<
				mizuiro::detail::bit_count_at_least
			>,
			metal::always<
				Bits
			>,
			metal::_1
		>
	>
>;

}
}

#endif
