//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_DETAIL_COPY_N_OVERLAP_HPP_INCLUDED
#define MIZUIRO_DETAIL_COPY_N_OVERLAP_HPP_INCLUDED

#include <fcppt/preprocessor/ignore_unsafe_buffer_usage_in_libc_call.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <mizuiro/detail/copy_n_base.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <cstring>
#include <fcppt/config/external_end.hpp>

namespace mizuiro::detail
{

template <typename Source, typename Size, typename Dest>
inline void copy_n_overlap(Source const *const _src, Size const _size, Dest *const _dest) noexcept
{
FCPPT_PP_PUSH_WARNING
FCPPT_PP_IGNORE_UNSAFE_BUFFER_USAGE_IN_LIBC_CALL
  mizuiro::detail::copy_n_base(
      [](void *const _vdest, void const *const _vsource, std::size_t const _ssize) noexcept
      { return std::memmove(_vdest, _vsource, _ssize); },
      _src,
      _size,
      _dest);
FCPPT_PP_POP_WARNING
}

}

#endif
