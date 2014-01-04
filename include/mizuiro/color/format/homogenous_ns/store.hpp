//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_HOMOGENOUS_NS_STORE_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_HOMOGENOUS_NS_STORE_HPP_INCLUDED

#include <mizuiro/color/format/homogenous_ns/tag.hpp>
#include <mizuiro/color/types/store_ns/tag.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <fcppt/config/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace types
{
namespace store_ns
{

template<
	typename Format
>
std::array<
	typename Format::channel_type,
	Format::element_count
>
store_adl(
	mizuiro::color::types::store_ns::tag,
	mizuiro::color::format::homogenous_ns::tag<
		Format
	>
);

}
}
}
}

#endif
