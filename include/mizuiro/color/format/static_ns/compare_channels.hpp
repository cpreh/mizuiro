//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_STATIC_NS_COMPARE_CHANNELS_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_STATIC_NS_COMPARE_CHANNELS_HPP_INCLUDED

#include <mizuiro/color/access/compare_channels_ns/tag.hpp>
#include <mizuiro/color/format/store_fwd.hpp>
#include <mizuiro/color/format/static_ns/tag.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <type_traits>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace access
{
namespace compare_channels_ns
{

template<
	typename Format,
	typename StaticChannel,
	typename OtherChannel
>
inline
constexpr
bool
compare_channels_adl(
	mizuiro::color::access::compare_channels_ns::tag,
	mizuiro::color::format::static_ns::tag<
		Format
	>,
	mizuiro::color::format::store<
		Format
	> const &,
	StaticChannel const &,
	OtherChannel const &
)
{
	return
		std::is_same<
			StaticChannel,
			OtherChannel
		>::value;
}

}
}
}
}

#endif
