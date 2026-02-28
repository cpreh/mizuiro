//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_ALGORITHM_MAKE_ITERATOR_IDENTITY_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_MAKE_ITERATOR_IDENTITY_HPP_INCLUDED

namespace mizuiro::image::algorithm
{

struct make_iterator_identity
{
  template <typename View>
  static View::iterator begin(View const &_view)
  {
    return _view.begin();
  }

  template <typename View>
  static View::iterator end(View const &_view)
  {
    return _view.end();
  }
};

}

#endif
