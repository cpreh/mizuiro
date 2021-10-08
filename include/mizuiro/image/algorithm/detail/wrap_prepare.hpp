//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_ALGORITHM_DETAIL_WRAP_PREPARE_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_DETAIL_WRAP_PREPARE_HPP_INCLUDED

#include <mizuiro/image/algorithm/detail/prepare.hpp>
#include <mizuiro/image/format/store_fwd.hpp>

namespace mizuiro::image::algorithm::detail
{

template <typename Access, typename ImageFormat, typename Function>
inline mizuiro::image::algorithm::detail::prepare<Access, ImageFormat, Function> wrap_prepare(
    mizuiro::image::format::store<ImageFormat> const &_format_store, Function const &_function)
{
  return mizuiro::image::algorithm::detail::prepare<Access, ImageFormat, Function>(
      _format_store, _function);
}

}

#endif
