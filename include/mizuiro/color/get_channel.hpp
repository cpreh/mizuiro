//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_GET_CHANNEL_HPP_INCLUDED
#define MIZUIRO_GET_CHANNEL_HPP_INCLUDED

#include <fcppt/tag_fwd.hpp>


namespace mizuiro
{
namespace color
{

template<
	typename Type
>
inline
Type
get_channel(
	Type const &_value
)
{
	return
		_value;
}

template<
	typename Type
>
inline
Type
get_channel(
	fcppt::tag<
		Type
	> const &
)
{
	return
		Type{};
}

}
}

#endif
