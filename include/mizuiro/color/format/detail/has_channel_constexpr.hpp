//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_DETAIL_HAS_CHANNEL_CONSTEXPR_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_DETAIL_HAS_CHANNEL_CONSTEXPR_HPP_INCLUDED

#include <mizuiro/color/access/has_channel.hpp>
#include <mizuiro/color/format/store.hpp>
#include <mizuiro/mpl/false.hpp>
#include <mizuiro/mpl/true.hpp>


namespace mizuiro
{
namespace color
{
namespace format
{
namespace detail
{

// TODO: Find a way to abstract this
template<
	int
>
struct int_to_true
:
mizuiro::mpl::true_
{
};

template<
	typename Format,
	typename Channel
>
int_to_true<
	(
		mizuiro::color::access::has_channel(
			mizuiro::color::format::store<
				Format
			>{
				nullptr
			},
			Channel{}
		),
		0
	)
>
check_constexpr(
	int
);

template<
	typename,
	typename
>
mizuiro::mpl::false_
check_constexpr(
	...
);

template<
	typename Format,
	typename Channel
>
using
has_channel_constexpr
=
decltype(
	check_constexpr<
		Format,
		Channel
	>(
		0
	)
);

}
}
}
}

#endif
