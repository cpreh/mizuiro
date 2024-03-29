//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_DIMENSION_CONTENT_HPP_INCLUDED
#define MIZUIRO_IMAGE_DIMENSION_CONTENT_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <mizuiro/image/dimension_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <functional>
#include <numeric>
#include <fcppt/config/external_end.hpp>

namespace mizuiro::image
{

template <mizuiro::size_type Dim, typename ValueType>
ValueType dimension_content(mizuiro::image::dimension<Dim, ValueType> const &_dim)
{
  return std::accumulate(
      _dim.begin(), _dim.end(), static_cast<ValueType>(1), std::multiplies<ValueType>());
}

}

#endif
