//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_DETAIL_ITERATOR_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_ITERATOR_IMPL_HPP_INCLUDED

#include <mizuiro/image/detail/compare_iterator.hpp>
#include <mizuiro/image/detail/iterator_decl.hpp> // IWYU pragma: export
#include <mizuiro/image/detail/iterator_difference.hpp>
#include <fcppt/variant/apply.hpp>

template <typename Access, typename Format, typename Constness>
mizuiro::image::detail::iterator<Access, Format, Constness>::iterator(
    internal_type const &_internal)
    : internal_(_internal)
{
}

template <typename Access, typename Format, typename Constness>
mizuiro::image::detail::iterator<Access, Format, Constness>::internal_type const &
mizuiro::image::detail::iterator<Access, Format, Constness>::internal() const
{
  return internal_;
}

template <typename Access, typename Format, typename Constness>
mizuiro::image::detail::iterator<Access, Format, Constness>::pointer
mizuiro::image::detail::iterator<Access, Format, Constness>::data() const
{
  return fcppt::variant::apply([](auto const &_value) { return _value.data(); }, internal_);
}

template <typename Access, typename Format, typename Constness>
void mizuiro::image::detail::iterator<Access, Format, Constness>::advance(
    difference_type const _diff)
{
  internal_ = fcppt::variant::apply(
      [_diff](auto _value) { return internal_type{_value += _diff}; }, internal_);
}

template <typename Access, typename Format, typename Constness>
void mizuiro::image::detail::iterator<Access, Format, Constness>::increment()
{
  internal_ = fcppt::variant::apply([](auto _it) { return internal_type{++_it}; }, internal_);
}

template <typename Access, typename Format, typename Constness>
void mizuiro::image::detail::iterator<Access, Format, Constness>::decrement()
{
  internal_ = fcppt::variant::apply([](auto _it) { return internal_type{--_it}; }, internal_);
}

template <typename Access, typename Format, typename Constness>
mizuiro::image::detail::iterator<Access, Format, Constness>::difference_type
mizuiro::image::detail::iterator<Access, Format, Constness>::distance_to(
    iterator const &_other) const
{
  return fcppt::variant::apply(
      mizuiro::image::detail::iterator_difference<difference_type>(), internal_, _other.internal_);
}

template <typename Access, typename Format, typename Constness>
mizuiro::image::detail::iterator<Access, Format, Constness>::reference
mizuiro::image::detail::iterator<Access, Format, Constness>::dereference() const
{
  return fcppt::variant::apply([](auto const &_it) { return *_it; }, internal_);
}

template <typename Access, typename Format, typename Constness>
bool mizuiro::image::detail::iterator<Access, Format, Constness>::equal(
    iterator const &_other) const
{
  return fcppt::variant::apply(
      mizuiro::image::detail::compare_iterator(), internal_, _other.internal_);
}

#endif
