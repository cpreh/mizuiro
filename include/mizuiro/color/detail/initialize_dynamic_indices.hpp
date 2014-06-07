//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_DETAIL_INITIALIZE_DYNAMIC_INDICES_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_INITIALIZE_DYNAMIC_INDICES_HPP_INCLUDED

#include <mizuiro/color/detail/invalid_dynamic_index.hpp>


namespace mizuiro
{
namespace color
{
namespace detail
{

template<
	typename ChannelIndexArray,
	typename Layout
>
ChannelIndexArray const
initialize_dynamic_indices(
	Layout const &_layout
)
{
	ChannelIndexArray ret;

	ret.fill(
		mizuiro::color::detail::invalid_dynamic_index<
			typename
			ChannelIndexArray::value_type
		>()
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
				]
			)
		] =
			index;

	return
		ret;
}

}
}
}

#endif
