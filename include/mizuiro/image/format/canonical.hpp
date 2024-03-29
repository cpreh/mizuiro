//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_FORMAT_CANONICAL_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_CANONICAL_HPP_INCLUDED

#include <mizuiro/image/format/canonical_fwd.hpp> // IWYU pragma: keep

namespace mizuiro::image::format
{

template <typename DimType, typename Type>
class canonical
{
public:
  using dim = DimType;

  using element_type = Type;
};

}

#endif
