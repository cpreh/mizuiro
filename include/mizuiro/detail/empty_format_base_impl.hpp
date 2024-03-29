//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_DETAIL_EMPTY_FORMAT_BASE_IMPL_HPP_INCLUDED
#define MIZUIRO_DETAIL_EMPTY_FORMAT_BASE_IMPL_HPP_INCLUDED

#include <mizuiro/detail/empty_format_base_decl.hpp> // IWYU pragma: export
#include <mizuiro/detail/empty_format_store_impl.hpp> // IWYU pragma: keep

template <typename Store>
constexpr mizuiro::detail::empty_format_base<Store>::empty_format_base(format_store_type const &)
{
}

template <typename Store>
constexpr typename mizuiro::detail::empty_format_base<Store>::format_store_type
mizuiro::detail::empty_format_base<Store>::format_store_base() const
{
  return format_store_type{};
}

#endif
