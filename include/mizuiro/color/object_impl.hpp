//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_OBJECT_IMPL_HPP_INCLUDED
#define MIZUIRO_COLOR_OBJECT_IMPL_HPP_INCLUDED

#include <mizuiro/const_tag.hpp>
#include <mizuiro/default_init_fwd.hpp>
#include <mizuiro/no_init_fwd.hpp>
#include <mizuiro/nonconst_tag.hpp>
#include <mizuiro/color/is_color.hpp>
#include <mizuiro/color/object_decl.hpp> // IWYU pragma: export
#include <mizuiro/color/proxy_impl.hpp> // IWYU pragma: keep
#include <mizuiro/color/access/init_store.hpp>
#include <mizuiro/color/access/store_data.hpp>
#include <mizuiro/color/format/base_impl.hpp> // IWYU pragma: keep
#include <mizuiro/color/format/store_impl.hpp> // IWYU pragma: keep
#include <mizuiro/color/init/detail/assign_object.hpp>
#include <mizuiro/color/init/detail/values_fwd.hpp>
#include <mizuiro/color/types/channel_reference.hpp>
#include <mizuiro/color/types/channel_value.hpp>
#include <mizuiro/color/types/store_needs_init.hpp>
#include <fcppt/no_init.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

template <typename Format>
mizuiro::color::object<Format>::object(mizuiro::no_init const &, format_store_type const &_format)
    : base(_format), data_{fcppt::no_init{}}
{
  static_assert(!mizuiro::color::types::store_needs_init<Format>::value);
}

template <typename Format>
mizuiro::color::object<Format>::object(
    mizuiro::default_init const &, format_store_type const &_format)
    : base(_format), data_(mizuiro::color::access::init_store<Format>())
{
}

template <typename Format>
template <typename Other>
mizuiro::color::object<Format>::object(Other const &_other)
  requires(mizuiro::color::is_color<Other>::value)
    : object(_other, mizuiro::color::types::store_needs_init<Format>{})
{
}

template <typename Format>
template <typename Vector>
mizuiro::color::object<Format>::object(
    mizuiro::color::init::detail::values<Vector> const &_init, format_store_type const &_format)
    : object{_init, mizuiro::color::types::store_needs_init<Format>{}, _format}
{
}

template <typename Format>
template <typename Channel>
void mizuiro::color::object<Format>::set(
    Channel const &_channel, mizuiro::color::types::channel_value<format, Channel> const &_ref)
{
  this->make_proxy().set(_channel, _ref);
}

template <typename Format>
template <typename Channel>
mizuiro::color::types::channel_reference<
    typename mizuiro::color::object<Format>::access,
    typename mizuiro::color::object<Format>::format,
    Channel,
    mizuiro::const_tag>
mizuiro::color::object<Format>::get(Channel const &_channel) const
{
  return this->make_const_proxy().get(_channel);
}

template <typename Format>
typename mizuiro::color::object<Format>::pointer mizuiro::color::object<Format>::data()
{
  return this->make_proxy().data();
}

template <typename Format>
typename mizuiro::color::object<Format>::const_pointer mizuiro::color::object<Format>::data() const
{
  return this->make_const_proxy().data();
}

template <typename Format>
constexpr typename mizuiro::color::object<Format>::format_store_type
mizuiro::color::object<Format>::format_store() const
{
  return this->format_store_base();
}

template <typename Format>
typename mizuiro::color::object<Format>::proxy mizuiro::color::object<Format>::make_proxy()
{
  return proxy(
      mizuiro::color::access::store_data<mizuiro::nonconst_tag, Format>(
          this->format_store(), data_),
      this->format_store());
}

template <typename Format>
typename mizuiro::color::object<Format>::const_proxy
mizuiro::color::object<Format>::make_const_proxy() const
{
  return const_proxy(
      mizuiro::color::access::store_data<mizuiro::const_tag, Format>(this->format_store(), data_),
      this->format_store());
}

template <typename Format>
template <typename Other>
mizuiro::color::object<Format>::object(Other const &_other, std::false_type)
    : base(_other.format_store()), data_(fcppt::no_init{})
{
  this->make_proxy() = _other;
}

template <typename Format>
template <typename Other>
mizuiro::color::object<Format>::object(Other const &_other, std::true_type)
    : base(_other.format_store()), data_(mizuiro::color::access::init_store<Format>())
{
  this->make_proxy() = _other;
}

template <typename Format>
template <typename Vector>
mizuiro::color::object<Format>::object(
    mizuiro::color::init::detail::values<Vector> const &_init,
    std::false_type,
    format_store_type const &_format)
    : base(_format), data_{fcppt::no_init{}}
{
  mizuiro::color::init::detail::assign_object(*this, _init);
}

template <typename Format>
template <typename Vector>
mizuiro::color::object<Format>::object(
    mizuiro::color::init::detail::values<Vector> const &_init,
    std::true_type,
    format_store_type const &_format)
    : base(_format), data_(mizuiro::color::access::init_store<Format>())
{
  mizuiro::color::init::detail::assign_object(*this, _init);
}

#endif
