//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mizuiro/color/object.hpp>
#include <mizuiro/color/output.hpp>
#include <mizuiro/color/format/homogenous_static.hpp>
#include <mizuiro/color/format/include/homogenous_static.hpp> // NOLINT(misc-include-cleaner)
#include <mizuiro/color/init/alpha.hpp>
#include <mizuiro/color/init/blue.hpp>
#include <mizuiro/color/init/green.hpp>
#include <mizuiro/color/init/red.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <mizuiro/image/bound.hpp>
#include <mizuiro/image/const_view.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/image/pitch_view_impl.hpp> // NOLINT(misc-include-cleaner)
#include <mizuiro/image/store.hpp>
#include <mizuiro/image/sub_view.hpp>
#include <mizuiro/image/to_pitch_view.hpp>
#include <mizuiro/image/algorithm/fill_indexed.hpp>
#include <mizuiro/image/algorithm/print.hpp>
#include <mizuiro/image/algorithm/uninitialized.hpp>
#include <mizuiro/image/format/interleaved.hpp>
#include <mizuiro/image/format/include/interleaved_homogenous.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <iterator>
#include <fcppt/config/external_end.hpp>

int main()
{
  using channel_type = float;

  using format = mizuiro::image::format::interleaved<
      mizuiro::image::dimension<3>,
      mizuiro::color::format::homogenous_static<channel_type, mizuiro::color::layout::rgba>>;

  using store = mizuiro::image::store<format>;

  using view_type = store::view_type;

  using bound_type = view_type::bound_type;

  store const img{
      store::dim(100U, 100U, 100U),
      [](view_type const &_view)
      {
        mizuiro::image::algorithm::fill_indexed(
            _view,
            [](view_type::dim const _index)
            {
              return mizuiro::color::object<format::color_format>(
                  (mizuiro::color::init::red() = static_cast<channel_type>(_index.at_c<0>()))(
                      mizuiro::color::init::green() = static_cast<channel_type>(_index.at_c<1>()))(
                      mizuiro::color::init::blue() = static_cast<channel_type>(_index.at_c<2>()))(
                      mizuiro::color::init::alpha() =
                          channel_type{
                              255}) // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
              );
            },
            mizuiro::image::algorithm::uninitialized::yes);
      }};

  std::cout << '\n';

  using pitch_view = mizuiro::image::to_pitch_view<typename mizuiro::image::const_view<view_type>>;

  pitch_view const sub_view(mizuiro::image::sub_view(
      img.view(),
      bound_type(
          bound_type::pos_t(bound_type::dim(1U, 1U, 1U)),
          bound_type::size_t(bound_type::dim(3U, 4U, 3U)))));

  std::cout << "sub image (with pitch " << sub_view.pitch() << ")\n";

  pitch_view const sub_sub_view(mizuiro::image::sub_view(
      sub_view,
      bound_type(
          bound_type::pos_t(bound_type::dim(1U, 1U, 1U)),
          bound_type::size_t(bound_type::dim(2U, 3U, 2U)))));

  std::cout << "sub sub image (with pitch " << sub_sub_view.pitch() << ")\n";

  mizuiro::image::algorithm::print(std::cout, sub_sub_view);

  std::cout << '\n';

  {
    using reverse_iterator = std::reverse_iterator<pitch_view::iterator>;

    for (reverse_iterator it(sub_sub_view.end()); it != reverse_iterator(sub_sub_view.begin());
         ++it)
    {
      std::cout << *it << ' ';
    }
  }

  std::cout << '\n';
}
