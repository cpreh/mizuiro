//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERT_DETAIL_EXCLUDE_CHANNEL_FUNCTOR_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERT_DETAIL_EXCLUDE_CHANNEL_FUNCTOR_HPP_INCLUDED

#include <mizuiro/color/access/compare_channels.hpp>

namespace mizuiro
{
namespace color
{
namespace detail
{

template<
	typename Format,
	typename StaticChannel
>
struct exclude_channel_functor
{
	typedef bool result_type;

	template<
		typename OtherChannel
	>
	bool
	operator()(
		OtherChannel const &_channel
	) const
	{
		return
			!color::access::compare_channels<
				Format,
				StaticChannel
			>::execute(
				_channel
			);
	}
};

}
}
}

#endif
