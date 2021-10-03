//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_COPY_N_HPP_INCLUDED
#define MIZUIRO_DETAIL_COPY_N_HPP_INCLUDED

#include <mizuiro/detail/copy_n_base.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <cstring>
#include <fcppt/config/external_end.hpp>


namespace mizuiro::detail
{

template<
	typename Source,
	typename Size,
	typename Dest
>
inline
void
copy_n(
	Source const *const _src, // NOLINT(readability-avoid-const-params-in-decls)
	Size const _size, // NOLINT(readability-avoid-const-params-in-decls)
	Dest *const _dest // NOLINT(readability-avoid-const-params-in-decls)
)
noexcept
{
	mizuiro::detail::copy_n_base(
		[](
			void *const _vdest,
			void const *const _vsource,
			std::size_t const _ssize
		)
		noexcept
		{
			return
				std::memcpy(
					_vdest,
					_vsource,
					_ssize
				);
		},
		_src,
		_size,
		_dest
	);
}

}

#endif
