//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_CONVERSION_DETAIL_RGB_FROM_CHROMA_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERSION_DETAIL_RGB_FROM_CHROMA_HPP_INCLUDED

#include <mizuiro/color/channel/blue.hpp>
#include <mizuiro/color/channel/green.hpp>
#include <mizuiro/color/channel/red.hpp>
#include <mizuiro/color/conversion/detail/chroma_tag.hpp>
#include <mizuiro/color/conversion/detail/diff_tag.hpp>
#include <mizuiro/color/conversion/detail/hue_part_tag.hpp>
#include <mizuiro/color/conversion/detail/largest_part_tag.hpp>
#include <mizuiro/color/conversion/detail/set_chroma_parts.hpp>
#include <fcppt/strong_typedef_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <exception>
#include <fcppt/config/external_end.hpp>

namespace mizuiro::color::conversion::detail
{

template <typename Dest, typename FloatType>
void rgb_from_chroma(
    Dest &_dest,
    fcppt::strong_typedef<FloatType, mizuiro::color::conversion::detail::chroma_tag> const _chroma,
    fcppt::strong_typedef<FloatType, mizuiro::color::conversion::detail::hue_part_tag> const
        _hue_part,
    fcppt::strong_typedef<FloatType, mizuiro::color::conversion::detail::largest_part_tag> const
        _largest_part,
    fcppt::strong_typedef<FloatType, mizuiro::color::conversion::detail::diff_tag> const _diff)
{
  using set_chroma_parts_type =
      mizuiro::color::conversion::detail::set_chroma_parts<Dest, FloatType>;

  set_chroma_parts_type const set_parts{
      _dest,
      typename set_chroma_parts_type::chroma_diff{_chroma.get() + _diff.get()},
      typename set_chroma_parts_type::largest_diff{_largest_part.get() + _diff.get()},
      typename set_chroma_parts_type::diff{_diff.get()}};

  switch (static_cast<int>(_hue_part.get()))
  {
  case 0:
    return set_parts(
        mizuiro::color::channel::red(),
        mizuiro::color::channel::green(),
        mizuiro::color::channel::blue());
  case 1: // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
    return set_parts(
        mizuiro::color::channel::green(),
        mizuiro::color::channel::red(),
        mizuiro::color::channel::blue());
  case 2: // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
    return set_parts(
        mizuiro::color::channel::green(),
        mizuiro::color::channel::blue(),
        mizuiro::color::channel::red());
  case 3: // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
    return set_parts(
        mizuiro::color::channel::blue(),
        mizuiro::color::channel::green(),
        mizuiro::color::channel::red());
  case 4: // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
    return set_parts(
        mizuiro::color::channel::blue(),
        mizuiro::color::channel::red(),
        mizuiro::color::channel::green());
  case 5: // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
    return set_parts(
        mizuiro::color::channel::red(),
        mizuiro::color::channel::blue(),
        mizuiro::color::channel::green());
  }

  std::terminate();
}

}

#endif
