//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_DETAIL_DYNAMIC_INITIALIZE_INDICES_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_DYNAMIC_INITIALIZE_INDICES_HPP_INCLUDED

#include <mizuiro/color/detail/dynamic/invalid_index.hpp>


namespace mizuiro
{
namespace color
{
namespace detail
{
namespace dynamic
{

template<
	typename ChannelIndexArray,
	typename Layout
>
ChannelIndexArray
initialize_indices(
	Layout const &_layout
)
{
	ChannelIndexArray ret;

	ret.fill(
		mizuiro::color::detail::dynamic::invalid_index()
	);

	for(
		typename Layout::size_type index(
			0
		);
		index < _layout.size();
		++index
	)
		ret[
			static_cast<
				typename ChannelIndexArray::size_type
			>(
				_layout[
					index
				].get()
			)
		] =
			index;

	return
		ret;
}

}
}
}
}

#endif
