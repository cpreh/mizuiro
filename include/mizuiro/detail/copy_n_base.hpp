//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_COPY_N_BASE_HPP_INCLUDED
#define MIZUIRO_DETAIL_COPY_N_BASE_HPP_INCLUDED

#include <mizuiro/detail/external_begin.hpp>
#include <cstddef>
#include <type_traits>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace detail
{

template<
	typename Function,
	typename Source,
	typename Size,
	typename Dest
>
inline
void
copy_n_base(
	Function const &_function,
	Source const *const _src,
	Size const _size,
	Dest *const _dest
)
noexcept
{
	static_assert(
		std::is_fundamental<
			Source
		>::value
		&&
		std::is_fundamental<
			Dest
		>::value,
		"Source and Dest must be fundamental types"
	);

	_function(
		static_cast<
			void *
		>(
			_dest
		),
		static_cast<
			void const *
		>(
			_src
		),
		static_cast<
			std::size_t
		>(
			_size
			*
			static_cast<
				Size
			>(
				sizeof(
					Source
				)
			)
		)
	);
}

}
}

#endif
