//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mizuiro/size_type.hpp>
#include <mizuiro/color/output.hpp> // NOLINT(misc-include-cleaner)
#include <mizuiro/color/convert_static/converter.hpp>
#include <mizuiro/color/format/homogenous_static.hpp>
#include <mizuiro/color/format/include/homogenous_static.hpp> // NOLINT(misc-include-cleaner)
#include <mizuiro/color/layout/rgb.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/image/dimension_null.hpp>
#include <mizuiro/image/make_raw_view.hpp>
#include <mizuiro/image/store.hpp>
#include <mizuiro/image/algorithm/copy_and_convert.hpp>
#include <mizuiro/image/algorithm/may_overlap.hpp>
#include <mizuiro/image/algorithm/print.hpp>
#include <mizuiro/image/algorithm/uninitialized.hpp>
#include <mizuiro/image/format/interleaved.hpp>
#include <mizuiro/image/format/include/interleaved_homogenous.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/array/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <cstdint>
#include <exception>
#include <iostream>
#include <fcppt/config/external_end.hpp>

namespace
{

template <typename Format>
using make_2d_format = mizuiro::image::format::interleaved<mizuiro::image::dimension<2>, Format>;

}

int main()
try
{
  using base_type = std::uint8_t;

  using rgba_format = make_2d_format<
      mizuiro::color::format::homogenous_static<base_type, mizuiro::color::layout::rgba>>;

  using rgb_format = make_2d_format<
      mizuiro::color::format::homogenous_static<base_type, mizuiro::color::layout::rgb>>;

  using rgba_format = make_2d_format<
      mizuiro::color::format::homogenous_static<base_type, mizuiro::color::layout::rgba>>;

  constexpr mizuiro::size_type const width{3};

  constexpr mizuiro::size_type const height{4};

  using raw_array = fcppt::array::object<
      unsigned char,
      width * height * sizeof(base_type) * rgb_format::color_format::element_count>;

  auto const uc([](int const _v) { return static_cast<unsigned char>(_v); });

  raw_array const data{uc(152), uc(34), uc(0), uc(232), uc(52),  uc(0),  uc(232), uc(52), uc(0),
                       uc(232), uc(52), uc(0), uc(232), uc(52),  uc(0),  uc(232), uc(52), uc(0),
                       uc(232), uc(52), uc(0), uc(232), uc(52),  uc(0),  uc(232), uc(52), uc(0),
                       uc(229), uc(59), uc(0), uc(151), uc(228), uc(15), uc(0),   uc(39), uc(4)};

  using rgba_store = mizuiro::image::store<rgba_format>;

  rgba_store::dim const dim(width, height);

  rgba_store store(
      dim,
      [dim, &data](rgba_store::view_type const &_dest)
      {
        mizuiro::image::algorithm::copy_and_convert<mizuiro::color::convert_static::converter>(
            mizuiro::image::make_raw_view<rgb_format>(
                data.data(),
                dim,
                mizuiro::image::dimension_null<rgba_store::view_type::pitch_type>()),
            _dest,
            mizuiro::image::algorithm::may_overlap::no,
            mizuiro::image::algorithm::uninitialized::yes);
      });

  mizuiro::image::algorithm::print(std::cout, store.view());

  std::cout << '\n';
}
catch(std::exception const &_error)
{
  std::cerr << _error.what() << '\n';
  return EXIT_FAILURE;
}
