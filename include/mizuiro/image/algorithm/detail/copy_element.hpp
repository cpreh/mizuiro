//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_ALGORITHM_DETAIL_COPY_ELEMENT_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_DETAIL_COPY_ELEMENT_HPP_INCLUDED

namespace mizuiro::image::algorithm::detail
{

struct copy_element
{
  template <typename Src, typename Dest>
  void operator()(Src const &_src, Dest const &_dest) const
  {
    _dest = _src;
  }
};

}

#endif
