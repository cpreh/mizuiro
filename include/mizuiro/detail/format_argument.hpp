//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_DETAIL_FORMAT_ARGUMENT_HPP_INCLUDED
#define MIZUIRO_DETAIL_FORMAT_ARGUMENT_HPP_INCLUDED

#include <mizuiro/detail/format_argument_impl.hpp>
#include <mizuiro/detail/format_store_impl.hpp>

namespace mizuiro::detail
{

template <typename Format, template <typename> class FormatNeedsStore, typename Copy>
struct format_argument
{
  using result_type = mizuiro::detail::format_store<Format, FormatNeedsStore, Copy>;

  static result_type get()
  {
    return mizuiro::detail::format_argument_impl<result_type, FormatNeedsStore<Format>::value>();
  }
};

}

#endif
