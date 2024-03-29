//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_ALGORITHM_COPY_AND_CONVERT_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_COPY_AND_CONVERT_HPP_INCLUDED

#include <mizuiro/decltype.hpp>
#include <mizuiro/color/convert.hpp>
#include <mizuiro/color/format/get.hpp>
#include <mizuiro/image/algorithm/can_copy_v.hpp>
#include <mizuiro/image/algorithm/copy.hpp>
#include <mizuiro/image/algorithm/make_iterator_identity.hpp>
#include <mizuiro/image/algorithm/may_overlap.hpp>
#include <mizuiro/image/algorithm/transform.hpp>
#include <mizuiro/image/algorithm/uninitialized.hpp>

namespace mizuiro::image::algorithm
{

template <typename Converter, typename ViewS, typename ViewD>
inline void copy_and_convert(
    ViewS const &_src,
    ViewD const &_dest,
    mizuiro::image::algorithm::may_overlap,
    mizuiro::image::algorithm::uninitialized const _uninitialized)
  requires(!mizuiro::image::algorithm::can_copy_v<ViewS, ViewD>)
{
  mizuiro::image::algorithm::transform(
      _src,
      _dest,
      [](auto const &_src_inner, auto const &_dest_inner)
      {
        _dest_inner = mizuiro::color::
            convert<Converter, mizuiro::color::format::get<MIZUIRO_DECLTYPE(_dest_inner)>>(
                _src_inner, _dest_inner.format_store());
      },
      mizuiro::image::algorithm::make_iterator_identity{},
      _uninitialized);
}

template <typename Converter, typename ViewS, typename ViewD>
inline void copy_and_convert(
    ViewS const &_src,
    ViewD const &_dest,
    mizuiro::image::algorithm::may_overlap const _overlap,
    mizuiro::image::algorithm::uninitialized const _uninitialized)
  requires(mizuiro::image::algorithm::can_copy_v<ViewS, ViewD>)
{
  mizuiro::image::algorithm::copy(_src, _dest, _overlap, _uninitialized);
}
}

#endif
