//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_DYNAMIC_NS_TYPES_VALID_CHANNEL_TYPE_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_DYNAMIC_NS_TYPES_VALID_CHANNEL_TYPE_HPP_INCLUDED

#include <mizuiro/color/detail/dynamic/channel_index_fwd.hpp>
#include <mizuiro/color/format/dynamic_ns/tag.hpp>
#include <mizuiro/color/types/valid_channel_type_ns/tag.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <type_traits>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace types
{
namespace valid_channel_type_ns
{
template<
	typename Format,
	typename Type
>
std::is_same<
	Type,
	mizuiro::color::detail::dynamic::channel_index
>
valid_channel_type_adl(
	mizuiro::color::types::valid_channel_type_ns::tag,
	mizuiro::color::format::dynamic_ns::tag<
		Format
	>,
	Type
);

}
}

}
}

#endif
