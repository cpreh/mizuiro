//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_INIT_DETAIL_IS_CHANNEL_INIT_HPP_INCLUDED
#define MIZUIRO_COLOR_INIT_DETAIL_IS_CHANNEL_INIT_HPP_INCLUDED

#include <mizuiro/detail/external_begin.hpp>
#include <type_traits>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace init
{
namespace detail
{

template<
	typename Channel
>
struct is_channel_init
{
	template<
		typename Type
	>
	static
	constexpr
	bool
	apply()
	{
		return
			std::is_same<
				typename
				Type::channel_type,
				Channel
			>::value;
	}
};

}
}
}
}

#endif
