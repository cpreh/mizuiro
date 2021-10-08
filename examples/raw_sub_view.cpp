//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mizuiro/nonconst_tag.hpp>
#include <mizuiro/size_type.hpp>
#include <mizuiro/access/raw.hpp>
#include <mizuiro/color/object.hpp>
#include <mizuiro/color/output.hpp>
#include <mizuiro/color/proxy.hpp>
#include <mizuiro/color/format/homogenous_static.hpp>
#include <mizuiro/color/format/include/homogenous_static.hpp>
#include <mizuiro/color/init/alpha.hpp>
#include <mizuiro/color/init/blue.hpp>
#include <mizuiro/color/init/green.hpp>
#include <mizuiro/color/init/red.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/image/dimension_null.hpp>
#include <mizuiro/image/make_raw_view.hpp>
#include <mizuiro/image/pitch_view_impl.hpp>
#include <mizuiro/image/sub_view.hpp>
#include <mizuiro/image/algorithm/fill_indexed.hpp>
#include <mizuiro/image/algorithm/print.hpp>
#include <mizuiro/image/algorithm/uninitialized.hpp>
#include <mizuiro/image/format/interleaved.hpp>
#include <mizuiro/image/format/include/interleaved_homogenous.hpp>
#include <fcppt/no_init.hpp>
#include <fcppt/array/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <ostream>
#include <fcppt/config/external_end.hpp>

int main()
{
  using channel_type = float;

  using dim = mizuiro::image::dimension<3>;

  using format = mizuiro::image::format::interleaved<
      dim,
      mizuiro::color::format::homogenous_static<channel_type, mizuiro::color::layout::rgba>>;

  constexpr mizuiro::size_type const width{4};

  constexpr mizuiro::size_type const height{4};

  constexpr mizuiro::size_type const depth{4};

  fcppt::array::object<
      unsigned char,
      width * height * depth * sizeof(float) * format::color_format::element_count>
      raw_data{fcppt::no_init{}};

  using view_type = mizuiro::image::pitch_view<mizuiro::access::raw, format, mizuiro::nonconst_tag>;

  using bound_type = view_type::bound_type;

  view_type const view(mizuiro::image::make_raw_view<format>(
      raw_data.data(),
      dim(width, height, depth),
      mizuiro::image::dimension_null<view_type::pitch_type>()));

  mizuiro::image::algorithm::fill_indexed(
      view,
      [](view_type::dim const _index)
      {
        return mizuiro::color::object<format::color_format>((
            mizuiro::color::init::red() = static_cast<channel_type>(_index.at_c<0>()))(
            mizuiro::color::init::green() = static_cast<channel_type>(_index.at_c<1>()))(
            mizuiro::color::init::blue() = static_cast<channel_type>(_index.at_c<2>()))(
            mizuiro::color::init::alpha() =
                channel_type{
                    255}) // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
        );
      },
      mizuiro::image::algorithm::uninitialized::yes);

  view_type const sub_view(mizuiro::image::sub_view(
      view,
      bound_type(
          bound_type::pos_t(bound_type::dim(1U, 1U, 0U)),
          bound_type::size_t(bound_type::dim(2U, 3U, 2U)))));

  std::cout << "sub_view.pitch(): " << sub_view.pitch() << '\n';

  mizuiro::image::algorithm::print(std::cout, sub_view);

  std::cout << '\n';
}
