//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_ALGORITHM_DETAIL_COPY_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_DETAIL_COPY_IMPL_HPP_INCLUDED

#include <mizuiro/image/algorithm/can_copy_in_place.hpp>
#include <mizuiro/image/algorithm/copy_different_channel_order.hpp>
#include <mizuiro/image/algorithm/copy_same_channel_order.hpp>
#include <mizuiro/image/algorithm/may_overlap.hpp>
#include <mizuiro/image/algorithm/uninitialized.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace mizuiro::image::algorithm::detail
{

template <typename ViewS, typename ViewD>
typename std::enable_if<!mizuiro::image::algorithm::can_copy_in_place<ViewS, ViewD>::value, void>::
    type
    copy_impl(
        ViewS const &_src,
        ViewD const &_dest,
        mizuiro::image::algorithm::may_overlap const _overlap,
        mizuiro::image::algorithm::uninitialized const _uninitialized)
{
  mizuiro::image::algorithm::copy_different_channel_order(_src, _dest, _overlap, _uninitialized);
}

template <typename ViewS, typename ViewD>
typename std::enable_if<mizuiro::image::algorithm::can_copy_in_place<ViewS, ViewD>::value, void>::
    type
    copy_impl(
        ViewS const &_src,
        ViewD const &_dest,
        mizuiro::image::algorithm::may_overlap const _overlap,
        mizuiro::image::algorithm::uninitialized const _uninitialized)
{
  mizuiro::image::algorithm::copy_same_channel_order(_src, _dest, _overlap, _uninitialized);
}

}

#endif
