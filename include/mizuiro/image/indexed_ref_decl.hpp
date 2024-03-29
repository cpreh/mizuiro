//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_INDEXED_REF_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_INDEXED_REF_DECL_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <mizuiro/image/dimension_impl.hpp>
#include <mizuiro/image/indexed_ref_fwd.hpp> // IWYU pragma: keep
#include <fcppt/reference_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace mizuiro::image
{

template <mizuiro::size_type Size, typename Reference>
class indexed_ref
{
public:
  using dim = mizuiro::image::dimension<Size>;

  indexed_ref(dim const &, Reference);

  [[nodiscard]] Reference get() const;

  [[nodiscard]] dim const &index() const;

private:
  dim index_;

  fcppt::reference<std::remove_reference_t<Reference>> reference_;
};

}

#endif
