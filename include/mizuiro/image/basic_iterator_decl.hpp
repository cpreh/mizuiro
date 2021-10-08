//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_BASIC_ITERATOR_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_BASIC_ITERATOR_DECL_HPP_INCLUDED

#include <mizuiro/image/basic_iterator_fwd.hpp>
#include <mizuiro/image/types/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <fcppt/config/external_end.hpp>

namespace mizuiro::image
{

template <typename Impl>
class basic_iterator final : public Impl
{
public:
  using impl = Impl;

  using value_type = mizuiro::image::types::value_type<typename Impl::format>;

  /**
	\brief The reference type of the underlying implementation

	This might be a proxy class which is not an lvalue.
	*/
  using reference = typename Impl::reference;

  /**
	\brief The pointer used to refer to data in the underlying implementation
	*/
  using pointer = typename Impl::pointer;

  using difference_type = typename Impl::difference_type;

  using iterator_category = std::random_access_iterator_tag;

  using format = typename Impl::format;

  using format_store_type = typename Impl::format_store_type;

  using Impl::Impl;

  [[nodiscard]] pointer data() const;

  [[nodiscard]] reference operator*() const;

  basic_iterator &operator++();

  [[nodiscard]] bool operator==(basic_iterator const &) const;

  [[nodiscard]] pointer operator->() const;

  basic_iterator() = delete;

  basic_iterator &operator--();

  basic_iterator &operator+=(difference_type);

  [[nodiscard]] difference_type operator-(basic_iterator const &) const;

  [[nodiscard]] reference operator[](difference_type) const;
};

template <typename Impl>
void swap(mizuiro::image::basic_iterator<Impl> &, mizuiro::image::basic_iterator<Impl> &);

template <typename Impl>
bool operator!=(
    mizuiro::image::basic_iterator<Impl> const &, mizuiro::image::basic_iterator<Impl> const &);

template <typename Impl>
mizuiro::image::basic_iterator<Impl> operator++(mizuiro::image::basic_iterator<Impl> &, int);

template <typename Impl>
mizuiro::image::basic_iterator<Impl> operator--(mizuiro::image::basic_iterator<Impl> &, int);

template <typename Impl>
mizuiro::image::basic_iterator<Impl> operator+(
    mizuiro::image::basic_iterator<Impl>,
    typename mizuiro::image::basic_iterator<Impl>::difference_type);

template <typename Impl>
mizuiro::image::basic_iterator<Impl> operator+(
    typename mizuiro::image::basic_iterator<Impl>::difference_type,
    mizuiro::image::basic_iterator<Impl> const &);

template <typename Impl>
mizuiro::image::basic_iterator<Impl> &operator-=(
    mizuiro::image::basic_iterator<Impl> &,
    typename mizuiro::image::basic_iterator<Impl>::difference_type);

template <typename Impl>
mizuiro::image::basic_iterator<Impl> operator-(
    mizuiro::image::basic_iterator<Impl>,
    typename mizuiro::image::basic_iterator<Impl>::difference_type);

template <typename Impl>
bool operator<(
    mizuiro::image::basic_iterator<Impl> const &, mizuiro::image::basic_iterator<Impl> const &);

template <typename Impl>
bool operator>(
    mizuiro::image::basic_iterator<Impl> const &, mizuiro::image::basic_iterator<Impl> const &);

template <typename Impl>
bool operator>=(
    mizuiro::image::basic_iterator<Impl> const &, mizuiro::image::basic_iterator<Impl> const &);

template <typename Impl>
bool operator<=(
    mizuiro::image::basic_iterator<Impl> const &, mizuiro::image::basic_iterator<Impl> const &);

}

#endif
