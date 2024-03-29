//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_FORMAT_CANONICAL_NS_TYPES_REFERENCE_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_CANONICAL_NS_TYPES_REFERENCE_HPP_INCLUDED

#include <mizuiro/apply_const.hpp>
#include <mizuiro/access/normal.hpp>
#include <mizuiro/color/proxy_impl.hpp> // IWYU pragma: keep
#include <mizuiro/image/format/canonical_ns/tag.hpp>
#include <mizuiro/image/types/reference_ns/tag.hpp>

namespace mizuiro::image::types::reference_ns
{

template <typename Format, typename Constness>
mizuiro::apply_const<typename Format::element_type &, Constness> reference_adl(
    mizuiro::image::types::reference_ns::tag,
    mizuiro::access::normal,
    mizuiro::image::format::canonical_ns::tag<Format>,
    Constness);

}

#endif
