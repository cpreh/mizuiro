//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_ACCESS_HOMOGENOUS_STATIC_HPP_INCLUDED
#define MIZUIRO_ACCESS_HOMOGENOUS_STATIC_HPP_INCLUDED

#include <mizuiro/color/is_homogenous_static.hpp>
#include <mizuiro/detail/index_of.hpp>
#include <mizuiro/size_type.hpp>

namespace mizuiro
{
namespace access
{

template<
	typename Access,
	typename Format,
	typename Channel
>
typename boost::enable_if<
	mizuiro::color::is_homogenous_static<
		Format
	>,
	mizuiro::size_type
>::type
channel_index(
	Access const &,
	Format const &,
	Channel const &
)
{
	return
		mizuiro::detail::index_of<
			typename Format::layout::order,
			Channel
		>::value;
}

}
}

#endif
