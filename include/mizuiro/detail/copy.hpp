//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_COPY_HPP_INCLUDED
#define MIZUIRO_DETAIL_COPY_HPP_INCLUDED

#include <mizuiro/detail/copy_n.hpp>
#include <iterator>

namespace mizuiro
{
namespace detail
{

template<
	typename Source,
	typename Dest
>
void
copy(
	Source const *const begin,
	Source const *const end,
	Dest *const dest
)
{
	return copy_n(
		begin,
		std::distance(
			begin,
			end
		),
		dest
	);
}

}
}

#endif
