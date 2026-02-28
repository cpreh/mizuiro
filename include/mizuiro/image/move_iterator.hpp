//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_MOVE_ITERATOR_HPP_INCLUDED
#define MIZUIRO_IMAGE_MOVE_ITERATOR_HPP_INCLUDED

namespace mizuiro::image
{

template <typename View>
View::iterator move_iterator(View const &_view, typename View::dim const _pos)
{
  typename View::iterator ret(_view.begin());

  using dim = View::dim;

  dim const size(_view.size());

  using difference_type = View::iterator::difference_type;

  difference_type add{0};

  difference_type multiplier{1};

  for (typename dim::size_type i = 0; i < dim::static_size; ++i)
  {
    // NOLINTNEXTLINE(cppcoreguidelines-pro-bounds-avoid-unchecked-container-access)
    add += static_cast<difference_type>(_pos[i]) * multiplier;

    // NOLINTNEXTLINE(cppcoreguidelines-pro-bounds-avoid-unchecked-container-access)
    multiplier *= static_cast<difference_type>(size[i]);
  }

  ret += add;

  return ret;
}

}

#endif
