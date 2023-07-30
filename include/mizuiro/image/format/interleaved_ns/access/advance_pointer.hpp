//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_FORMAT_INTERLEAVED_NS_ACCESS_ADVANCE_POINTER_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_INTERLEAVED_NS_ACCESS_ADVANCE_POINTER_HPP_INCLUDED

#include <mizuiro/difference_type.hpp>
#include <mizuiro/image/access/advance_pointer_ns/tag.hpp>
#include <mizuiro/image/format/store_fwd.hpp>
#include <mizuiro/image/format/color_ns/types/pointer.hpp>
#include <mizuiro/image/format/interleaved_ns/tag.hpp>
#include <mizuiro/image/types/pointer.hpp>
#include <fcppt/preprocessor/ignore_unsafe_buffer_usage.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>

namespace mizuiro::image::access::advance_pointer_ns
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_IGNORE_UNSAFE_BUFFER_USAGE

template <typename Access, typename ImageFormat, typename Constness>
mizuiro::image::types::pointer<Access, ImageFormat, Constness> advance_pointer_adl(
    mizuiro::image::access::advance_pointer_ns::tag,
    mizuiro::image::format::interleaved_ns::tag<ImageFormat>,
    Access,
    Constness,
    mizuiro::image::format::store<ImageFormat> const &,
    mizuiro::image::types::pointer<Access, ImageFormat, Constness> const _data,
    mizuiro::difference_type const _diff)
{
  return _data + _diff;
}

FCPPT_PP_POP_WARNING

}

#endif
