//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_ACCESS_STRIDE_HPP_INCLUDED
#define MIZUIRO_ACCESS_STRIDE_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <mizuiro/access/normal.hpp>
#include <mizuiro/access/raw.hpp>

namespace mizuiro::access
{

template <typename Elements, typename Multiplier>
inline mizuiro::size_type stride(mizuiro::access::normal)
{
  return Elements::value;
}

template <typename Elements, typename Multiplier>
inline mizuiro::size_type stride(mizuiro::access::raw)
{
  return mizuiro::access::stride<Elements, Multiplier>(mizuiro::access::normal()) *
         Multiplier::value;
}

}

#endif
