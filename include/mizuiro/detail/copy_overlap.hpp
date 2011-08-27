//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_COPY_OVERLAP_HPP_INCLUDED
#define MIZUIRO_DETAIL_COPY_OVERLAP_HPP_INCLUDED

#include <mizuiro/detail/copy_n_overlap.hpp>
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
copy_overlap(
	Source const *const _begin,
	Source const *const _end,
	Dest *const _dest
)
{
	return
		detail::copy_n_overlap(
			_begin,
			std::distance(
				_begin,
				_end
			),
			_dest
		);
}

}
}

#endif
