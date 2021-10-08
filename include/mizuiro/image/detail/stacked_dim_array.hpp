//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_DETAIL_STACKED_DIM_ARRAY_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_STACKED_DIM_ARRAY_HPP_INCLUDED

#include <mizuiro/image/dimension_decl.hpp>
#include <fcppt/array/object_impl.hpp>

namespace mizuiro::image::detail
{

template <typename Dim, typename ValueType = typename Dim::value_type>
using stacked_dim_array = fcppt::array::object<ValueType, Dim::static_size - 1>;

}

#endif
