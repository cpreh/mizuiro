//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_DETAIL_DYNAMIC_CHANNEL_INDEX_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_DYNAMIC_CHANNEL_INDEX_HPP_INCLUDED

#include <mizuiro/size_type.hpp>


namespace mizuiro
{
namespace color
{
namespace detail
{
namespace dynamic
{

class channel_index
{
public:
	explicit
	channel_index(
		mizuiro::size_type const _index
	)
	:
		index_{
			_index
		}
	{
	}

	mizuiro::size_type
	get() const
	{
		return
			index_;
	}
private:
	mizuiro::size_type index_;
};

}
}
}
}

#endif
