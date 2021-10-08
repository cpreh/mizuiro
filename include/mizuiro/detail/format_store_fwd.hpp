//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_DETAIL_FORMAT_STORE_FWD_HPP_INCLUDED
#define MIZUIRO_DETAIL_FORMAT_STORE_FWD_HPP_INCLUDED

#include <mizuiro/detail/empty_format_store_fwd.hpp>
#include <mizuiro/detail/normal_format_store_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace mizuiro::detail
{

template <typename Format, template <typename> class FormatNeedsStore, typename Copy>
using format_store = std::conditional_t<
    FormatNeedsStore<Format>::value,
    mizuiro::detail::normal_format_store<Format, Copy>,
    mizuiro::detail::empty_format_store<Format>>;

}

#endif
