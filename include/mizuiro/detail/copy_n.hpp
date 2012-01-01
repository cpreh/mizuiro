//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_COPY_N_HPP_INCLUDED
#define MIZUIRO_DETAIL_COPY_N_HPP_INCLUDED

#include <mizuiro/detail/copy_n_base.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <cstddef>
#include <cstring>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace detail
{

template<
	typename Source,
	typename Size,
	typename Dest
>
void
copy_n(
	Source const *const _src,
	Size const _size,
	Dest *const _dest
)
{
	detail::copy_n_base(
		std::memcpy,
		_src,
		_size,
		_dest
	);
}

}
}

#endif
