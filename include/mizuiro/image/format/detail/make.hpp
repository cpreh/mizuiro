//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_FORMAT_DETAIL_MAKE_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_DETAIL_MAKE_HPP_INCLUDED

#include <mizuiro/detail/copy_store.hpp>
#include <mizuiro/image/types/needs_format_store.hpp>

namespace mizuiro::image::format::detail
{

template <typename Format, template <typename, template <typename> class, typename> class Inner>
using make = Inner<Format, mizuiro::image::types::needs_format_store, mizuiro::detail::copy_store>;

}

#endif
