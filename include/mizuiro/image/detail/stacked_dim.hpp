//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_DETAIL_STACKED_DIM_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_STACKED_DIM_HPP_INCLUDED

#include <mizuiro/image/dimension_impl.hpp>
#include <mizuiro/image/detail/stacked_dim_array.hpp>
#include <fcppt/no_init.hpp>

namespace mizuiro::image::detail
{

template <typename RetValue, typename Dim>
mizuiro::image::detail::stacked_dim_array<mizuiro::image::dimension<Dim::static_size, RetValue>>
stacked_dim(Dim const &_dim)
{
  using stacked_type = mizuiro::image::detail::stacked_dim_array<
      mizuiro::image::dimension<Dim::static_size, RetValue>>;

  stacked_type ret{fcppt::no_init{}};

  typename Dim::value_type cur = 1;

  for (typename Dim::size_type i = 0; i < ret.size(); ++i)
  {
    cur *= _dim[i];

    ret.get_unsafe(i) = static_cast<typename stacked_type::value_type>(cur);
  }

  return ret;
}

}

#endif
