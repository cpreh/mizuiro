//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_FORMAT_HETEROGENOUS_STATIC_NS_TAG_OF_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_HETEROGENOUS_STATIC_NS_TAG_OF_HPP_INCLUDED

#include <mizuiro/color/format/heterogenous_static_fwd.hpp>
#include <mizuiro/color/format/tag_of_fwd.hpp>
#include <mizuiro/color/format/heterogenous_static_ns/tag.hpp>

namespace mizuiro::color::format
{

template <typename ChannelTypes, typename Layout>
struct tag_of<mizuiro::color::format::heterogenous_static<ChannelTypes, Layout>>
{
  using type = mizuiro::color::format::heterogenous_static_ns::tag<
      mizuiro::color::format::heterogenous_static<ChannelTypes, Layout>>;
};

}

#endif
