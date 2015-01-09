//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_INIT_DETAIL_TO_CHANNEL_TYPE_HPP_INCLUDED
#define MIZUIRO_COLOR_INIT_DETAIL_TO_CHANNEL_TYPE_HPP_INCLUDED


namespace mizuiro
{
namespace color
{
namespace init
{
namespace detail
{

struct to_channel_type
{
	template<
		typename Type
	>
	static
	constexpr
	typename
	Type::channel_type
	apply()
	{
		return
			typename
			Type::channel_type{};
	}
};

}
}
}
}

#endif
