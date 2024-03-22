//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_ALGORITHM_COPY_DIFFERENT_CHANNEL_ORDER_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_COPY_DIFFERENT_CHANNEL_ORDER_HPP_INCLUDED

#include <mizuiro/image/algorithm/make_iterator_identity.hpp>
#include <mizuiro/image/algorithm/may_overlap.hpp>
#include <mizuiro/image/algorithm/transform.hpp>
#include <mizuiro/image/algorithm/uninitialized.hpp>
#include <mizuiro/image/algorithm/detail/copy_element.hpp>
#include <mizuiro/image/types/value_type.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>

namespace mizuiro::image::algorithm
{

template <typename ViewS, typename ViewD>
void copy_different_channel_order(
    ViewS const &_src,
    ViewD const &_dest,
    mizuiro::image::algorithm::may_overlap const _overlap,
    mizuiro::image::algorithm::uninitialized const _uninitialized)
{
  mizuiro::image::algorithm::make_iterator_identity const make_iterator{};

  FCPPT_PP_PUSH_WARNING
  FCPPT_PP_DISABLE_GCC_WARNING(-Wswitch-default)
  switch (_overlap)
  {
  case mizuiro::image::algorithm::may_overlap::yes:
    mizuiro::image::algorithm::transform(
        _src,
        _dest,
        [](auto const &_src_inner, auto const &_dest_inner)
        {
          mizuiro::image::types::value_type<typename ViewS::format> const temp(_src_inner);

          _dest_inner = temp;
        },
        make_iterator,
        _uninitialized);
    return;
  case mizuiro::image::algorithm::may_overlap::no:
    mizuiro::image::algorithm::transform(
        _src,
        _dest,
        mizuiro::image::algorithm::detail::copy_element{},
        make_iterator,
        _uninitialized);
    return;
  }
  FCPPT_PP_POP_WARNING
}

}

#endif
