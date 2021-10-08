//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_PROXY_DECL_HPP_INCLUDED
#define MIZUIRO_COLOR_PROXY_DECL_HPP_INCLUDED

#include <mizuiro/const_tag.hpp>
#include <mizuiro/color/proxy_fwd.hpp>
#include <mizuiro/color/format/argument.hpp>
#include <mizuiro/color/format/base_decl.hpp>
#include <mizuiro/color/types/channel_reference.hpp>
#include <mizuiro/color/types/channel_value.hpp>
#include <mizuiro/color/types/pointer.hpp>

namespace mizuiro::color
{

template <typename Access, typename Format, typename Constness>
class proxy final : private mizuiro::color::format::base<Format>
{
  using base = mizuiro::color::format::base<Format>;

public:
  using access = Access;

  using format = Format;

  using format_store_type = typename base::format_store_type;

  using pointer = mizuiro::color::types::pointer<Access, Format, Constness>;

  explicit proxy(
      pointer data, format_store_type const & = mizuiro::color::format::argument<Format>::get());

  template <typename OtherConstness>
  explicit proxy(mizuiro::color::proxy<Access, Format, OtherConstness> const &);

  proxy(proxy const &);

  proxy(proxy &&) noexcept;

  template <typename Other>
  // NOLINTNEXTLINE(cppcoreguidelines-c-copy-assignment-signature,misc-unconventional-assign-operator)
  proxy const &operator=(Other const &) const;

  proxy &operator=(proxy const &) = delete;

  proxy &operator=(proxy &&) = delete;

  ~proxy();

  template <typename Channel>
  void set(Channel const &, mizuiro::color::types::channel_value<Format, Channel> const &) const;

  template <typename Channel>
  [[nodiscard]] mizuiro::color::types::
      channel_reference<Access, Format, Channel, mizuiro::const_tag>
      get(Channel const &) const;

  [[nodiscard]] pointer data() const;

  [[nodiscard]] format_store_type format_store() const;

private:
  pointer data_;
};

}

#endif
