//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_SUB_VIEW_HPP_INCLUDED
#define MIZUIRO_IMAGE_SUB_VIEW_HPP_INCLUDED

#include <mizuiro/image/bound_impl.hpp>
#include <mizuiro/image/move_iterator.hpp>
#include <mizuiro/image/pitch_view_impl.hpp>
#include <mizuiro/image/to_pitch_view.hpp>
#include <mizuiro/image/detail/subview_pitch.hpp>

namespace mizuiro::image
{

template <typename View>
mizuiro::image::to_pitch_view<View>
sub_view(View const &_view, typename View::bound_type const &_bound)
{
  return mizuiro::image::to_pitch_view<View>(
      _bound.size(),
      mizuiro::image::move_iterator(_view, _bound.pos()).data(),
      mizuiro::image::detail::subview_pitch(_view, _bound));
}

}

#endif
