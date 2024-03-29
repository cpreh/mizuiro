//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_ALGORITHM_DETAIL_PREPARE_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_DETAIL_PREPARE_HPP_INCLUDED

#include <mizuiro/image/prepare_store_units.hpp>
#include <mizuiro/image/format/store.hpp>
#include <fcppt/reference_impl.hpp>

namespace mizuiro::image::algorithm::detail
{

template <typename Access, typename ImageFormat, typename Function>
class prepare
{
public:
  prepare(
      mizuiro::image::format::store<ImageFormat> const &_format_store, Function const &_function)
      : format_store_(_format_store), function_(_function)
  {
  }

  template <typename Dest>
  void operator()(Dest const &_dest) const
  {
    mizuiro::image::prepare_store_units<Access, ImageFormat>(format_store_.get(), _dest);

    function_.get()(_dest);
  }

  template <typename Src, typename Dest>
  void operator()(Src const &_src, Dest const &_dest) const
  {
    mizuiro::image::prepare_store_units<Access, ImageFormat>(format_store_.get(), _dest);

    function_.get()(_src, _dest);
  }

private:
  fcppt::reference<mizuiro::image::format::store<ImageFormat> const> format_store_;

  fcppt::reference<Function const> function_;
};

}

#endif
