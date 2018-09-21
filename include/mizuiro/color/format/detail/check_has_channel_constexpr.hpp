//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_DETAIL_CHECK_HAS_CHANNEL_CONSTEXPR_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_DETAIL_CHECK_HAS_CHANNEL_CONSTEXPR_HPP_INCLUDED

#include <mizuiro/color/access/has_channel.hpp>
#include <mizuiro/color/format/store.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/types/integral_constant.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace format
{
namespace detail
{

template<
	typename Format,
	typename Channel
>
std::true_type
check_has_channel_constexpr(
	int,
	bool =
		brigand::bool_<
			mizuiro::color::access::has_channel<
				Format
			>(
				mizuiro::color::format::store<
					Format
				>{},
				Channel{}
			)
		>::value
);

template<
	typename,
	typename
>
std::false_type
check_has_channel_constexpr(
	...
);

}
}
}
}

#endif
