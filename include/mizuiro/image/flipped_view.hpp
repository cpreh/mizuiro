//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_FLIPPED_VIEW_HPP_INCLUDED
#define MIZUIRO_IMAGE_FLIPPED_VIEW_HPP_INCLUDED

#include <mizuiro/image/dimension_impl.hpp>
#include <mizuiro/image/move_iterator.hpp>
#include <mizuiro/image/pitch_view_impl.hpp>
#include <mizuiro/image/to_pitch_view.hpp>
#include <mizuiro/image/detail/flipped_edge.hpp>
#include <mizuiro/image/detail/flipped_pitch.hpp>
#include <mizuiro/image/detail/flipped_start.hpp>
#include <mizuiro/image/detail/pitch_difference.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace mizuiro::image
{

template <typename View>
std::enable_if_t<View::dim::static_size >= 2, mizuiro::image::to_pitch_view<View>>
flipped_view(View const &_view)
{
  using result_type = mizuiro::image::to_pitch_view<View>;

  using dim = typename View::dim;

  typename dim::value_type const last_dim(_view.size().back());

  return last_dim > 1 ? result_type(
                            _view.size(),
                            mizuiro::image::move_iterator(
                                _view, mizuiro::image::detail::flipped_start<dim>(last_dim))
                                .data(),
                            mizuiro::image::detail::flipped_pitch(
                                _view.pitch(),
                                image::detail::pitch_difference(
                                    mizuiro::image::move_iterator(
                                        _view, mizuiro::image::detail::flipped_edge(_view.size())),
                                    _view.begin()) +
                                    _view.pitch().back()))
                      : result_type(_view.size(), _view.data(), _view.pitch());
}

}

#endif
