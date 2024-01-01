//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_BOUND_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_BOUND_DECL_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <mizuiro/image/bound_fwd.hpp> // IWYU pragma: keep
#include <mizuiro/image/dimension_decl.hpp>
#include <fcppt/declare_strong_typedef.hpp>

namespace mizuiro::image
{

template <mizuiro::size_type Dim, typename ValueType>
class bound
{
public:
  using value_type = ValueType;

  using size_type = mizuiro::size_type;

  using dim = mizuiro::image::dimension<Dim, value_type>;

  FCPPT_DECLARE_STRONG_TYPEDEF(dim, pos_t);

  FCPPT_DECLARE_STRONG_TYPEDEF(dim, size_t);

  bound(pos_t const &, size_t const &);

  dim const &pos() const;

  dim const &size() const;

private:
  dim pos_, size_;
};

}

#endif
