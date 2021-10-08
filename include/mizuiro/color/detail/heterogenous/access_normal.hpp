//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_DETAIL_HETEROGENOUS_ACCESS_NORMAL_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_HETEROGENOUS_ACCESS_NORMAL_HPP_INCLUDED

#include <mizuiro/const_tag.hpp>
#include <mizuiro/integral_size.hpp>
#include <mizuiro/nonconst_tag.hpp>
#include <mizuiro/size_type.hpp>
#include <mizuiro/access/normal.hpp>
#include <mizuiro/color/detail/left_shift.hpp>
#include <mizuiro/color/detail/heterogenous/bits.hpp>
#include <mizuiro/color/detail/heterogenous/channel_bits.hpp>
#include <mizuiro/color/types/channel_value.hpp>
#include <mizuiro/color/types/pointer.hpp>
#include <mizuiro/detail/promote_type.hpp>
#include <mizuiro/detail/range_to.hpp>
#include <mizuiro/detail/sum.hpp>
#include <mizuiro/detail/uint_least.hpp>
#include <fcppt/mpl/list/index_of.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace mizuiro::color::detail::heterogenous
{

template <typename Format, typename Channel>
class access_normal
{
private:
  using value_type = mizuiro::color::types::channel_value<Format, Channel>;

  using start_bit = mizuiro::integral_size<mizuiro::detail::sum<mizuiro::detail::range_to<
      typename Format::channel_bits,
      fcppt::mpl::list::index_of<typename Format::layout::channels, Channel>::value>>::value>;

  using bit_count = mizuiro::color::detail::heterogenous::channel_bits<Format, Channel>;

  using const_pointer =
      mizuiro::color::types::pointer<mizuiro::access::normal, Format, mizuiro::const_tag>;

  using pointer =
      mizuiro::color::types::pointer<mizuiro::access::normal, Format, mizuiro::nonconst_tag>;

  using total_bits = mizuiro::color::detail::heterogenous::bits<typename Format::channel_bits>;

  using real_start_bit =
      mizuiro::integral_size<total_bits::value - bit_count::value - start_bit::value>;

  using color_uint = mizuiro::detail::uint_least<total_bits>;

  using promoted_color = std::make_unsigned_t<mizuiro::detail::promote_type<color_uint>>;

  template <mizuiro::size_type Begin, mizuiro::size_type Count>
  static constexpr color_uint bit_mask()
  {
    return static_cast<color_uint>(
        mizuiro::color::detail::left_shift<promoted_color, Begin>() ^
        mizuiro::color::detail::left_shift<promoted_color, Begin + Count>());
  }

public:
  static value_type read(const_pointer const _data)
  {
    return static_cast<value_type>(
        // NOLINTNEXTLINE(hicpp-signed-bitwise)
        (access_normal::bit_mask<real_start_bit::value, bit_count::value>() & *_data) >>
        real_start_bit::value);
  }

  static void write(pointer const _data, value_type const _value)
  {
    *_data = static_cast<color_uint>(
        // NOLINTNEXTLINE(hicpp-signed-bitwise)
        *_data & ~access_normal::bit_mask<real_start_bit::value, bit_count::value>());

    *_data = static_cast<color_uint>(
        // NOLINTNEXTLINE(hicpp-signed-bitwise)
        *_data | static_cast<color_uint>(_value) << real_start_bit::value);
  }
};

}

#endif
