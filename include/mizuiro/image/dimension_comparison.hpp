//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_DIMENSION_COMPARISON_HPP_INCLUDED
#define MIZUIRO_IMAGE_DIMENSION_COMPARISON_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <mizuiro/image/dimension_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>

namespace mizuiro::image
{

template <mizuiro::size_type Dim, typename ValueType>
bool operator==(
    mizuiro::image::dimension<Dim, ValueType> const &_a,
    mizuiro::image::dimension<Dim, ValueType> const &_b)
{
  return std::equal(_a.begin(), _a.end(), _b.begin());
}

template <mizuiro::size_type Dim, typename ValueType>
bool operator!=(
    mizuiro::image::dimension<Dim, ValueType> const &_a,
    mizuiro::image::dimension<Dim, ValueType> const &_b)
{
  return !(_a == _b);
}

}

#endif
