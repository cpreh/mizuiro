//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_DETAIL_NORMAL_FORMAT_STORE_IMPL_HPP_INCLUDED
#define MIZUIRO_DETAIL_NORMAL_FORMAT_STORE_IMPL_HPP_INCLUDED

#include <mizuiro/detail/copy_store.hpp>
#include <mizuiro/detail/normal_format_store_decl.hpp> // IWYU pragma: export
#include <mizuiro/detail/normal_format_store_fwd.hpp> // IWYU pragma: export
#include <mizuiro/detail/ref_store.hpp>

template <typename Format>
constexpr mizuiro::detail::normal_format_store<Format, mizuiro::detail::ref_store>::
    normal_format_store(ref const _format)
    : format_{_format}
{
}

template <typename Format>
inline Format const &
mizuiro::detail::normal_format_store<Format, mizuiro::detail::ref_store>::get() const
{
  return format_.get();
}

template <typename Format>
constexpr mizuiro::detail::normal_format_store<Format, mizuiro::detail::copy_store>::
    normal_format_store(Format const &_format)
    : format_{_format}
{
}

template <typename Format>
inline Format const &
mizuiro::detail::normal_format_store<Format, mizuiro::detail::copy_store>::get() const
{
  return format_;
}

#endif
