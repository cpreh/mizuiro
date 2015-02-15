//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_STATIC_NS_TYPES_VALID_CHANNEL_TYPE_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_STATIC_NS_TYPES_VALID_CHANNEL_TYPE_HPP_INCLUDED

#include <mizuiro/color/format/static_ns/tag.hpp>
#include <mizuiro/color/types/valid_channel_type_ns/tag.hpp>
#include <mizuiro/mpl/false.hpp>


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
mizuiro::mpl::false_
valid_channel_type_adl(
	mizuiro::color::types::valid_channel_type_ns::tag,
	mizuiro::color::format::static_ns::tag<
		Format
	>,
	Type
);

}
}

}
}

#endif
