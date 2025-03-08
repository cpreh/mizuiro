//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mizuiro/apply_const.hpp>
#include <mizuiro/difference_type.hpp>
#include <mizuiro/nonconst_tag.hpp>
#include <mizuiro/raw_pointer.hpp>
#include <mizuiro/raw_value.hpp>
#include <mizuiro/size_type.hpp>
#include <mizuiro/access/raw.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/image/dimension_content.hpp>
#include <mizuiro/image/linear_view.hpp>
#include <mizuiro/image/pitch_type.hpp>
#include <mizuiro/image/access/advance_pointer_ns/tag.hpp>
#include <mizuiro/image/access/dereference_ns/tag.hpp>
#include <mizuiro/image/access/pointer_difference_ns/tag.hpp>
#include <mizuiro/image/access/stride_ns/tag.hpp>
#include <mizuiro/image/algorithm/print.hpp>
#include <mizuiro/image/format/store_fwd.hpp>
#include <mizuiro/image/format/tag_of_fwd.hpp>
#include <mizuiro/image/types/pointer.hpp>
#include <mizuiro/image/types/reference.hpp>
#include <mizuiro/image/types/needs_format_store_ns/tag.hpp>
#include <mizuiro/image/types/pointer_ns/tag.hpp>
#include <mizuiro/image/types/reference_ns/tag.hpp>
#include <mizuiro/image/types/value_type_ns/tag.hpp>
#include <fcppt/preprocessor/ignore_unsafe_buffer_usage.hpp>
#include <fcppt/preprocessor/ignore_unsafe_buffer_usage_in_libc_call.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstring>
#include <iostream>
#include <iterator>
#include <type_traits>
#include <vector>
#include <fcppt/config/external_end.hpp>

namespace
{
namespace mylib
{

template <typename Format>
struct tag
{
};

template <typename Dim, typename Type>
struct native_format
{
  // Typedefs for mizuiro
  using dim = Dim;

  using pitch = mizuiro::image::pitch_type<dim>;

  // Own typedefs
  using type = Type;
};

template <typename Type>
class proxy;

}
}

namespace mizuiro::image
{
namespace format
{

template <typename Dim, typename Type>
struct tag_of<mylib::native_format<Dim, Type>>
{
  using type = mylib::tag<mylib::native_format<Dim, Type>>;
};

}

namespace types
{
namespace needs_format_store_ns
{

template <typename Dim, typename Type>
// NOLINTNEXTLINE(misc-use-internal-linkage)
std::false_type needs_format_store_adl(
    mizuiro::image::types::needs_format_store_ns::tag, mylib::tag<mylib::native_format<Dim, Type>>);

}

namespace pointer_ns
{

template <typename Dim, typename Type, typename Constness>
// NOLINTNEXTLINE(misc-use-internal-linkage)
mizuiro::apply_const<mizuiro::raw_pointer, Constness> pointer_adl(
    mizuiro::image::types::pointer_ns::tag,
    mizuiro::access::raw,
    mylib::tag<mylib::native_format<Dim, Type>>,
    Constness);

}

namespace reference_ns
{

template <typename Dim, typename Type>
// NOLINTNEXTLINE(misc-use-internal-linkage)
mylib::proxy<Type> reference_adl(
    mizuiro::image::types::reference_ns::tag,
    mizuiro::access::raw,
    mylib::tag<mylib::native_format<Dim, Type>>,
    mizuiro::nonconst_tag);

}

namespace value_type_ns
{

template <typename Dim, typename Type>
// NOLINTNEXTLINE(misc-use-internal-linkage)
Type value_type_adl(
    mizuiro::image::types::value_type_ns::tag, mylib::tag<mylib::native_format<Dim, Type>>);

}
}

namespace access
{
namespace advance_pointer_ns
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_IGNORE_UNSAFE_BUFFER_USAGE

template <typename Dim, typename Type, typename Constness>
mizuiro::image::types::pointer<mizuiro::access::raw, mylib::native_format<Dim, Type>, Constness>
// NOLINTNEXTLINE(misc-use-internal-linkage)
advance_pointer_adl(
    mizuiro::image::access::advance_pointer_ns::tag,
    mylib::tag<mylib::native_format<Dim, Type>>,
    mizuiro::access::raw,
    Constness,
    mizuiro::image::format::store<mylib::native_format<Dim, Type>> const &,
    mizuiro::image::types::
        pointer<mizuiro::access::raw, mylib::native_format<Dim, Type>, Constness> const _pointer,
    mizuiro::difference_type const _diff)
{
  return _pointer + _diff;
}

FCPPT_PP_POP_WARNING

}

namespace pointer_difference_ns
{
template <typename Dim, typename Type, typename Constness>
// NOLINTNEXTLINE(misc-use-internal-linkage)
mizuiro::difference_type pointer_difference_adl(
    mizuiro::image::access::pointer_difference_ns::tag,
    mylib::tag<mylib::native_format<Dim, Type>>,
    mizuiro::access::raw,
    Constness,
    mizuiro::image::format::store<mylib::native_format<Dim, Type>> const &,
    mizuiro::image::types::
        pointer<mizuiro::access::raw, mylib::native_format<Dim, Type>, Constness> const _pointer1,
    mizuiro::image::types::
        pointer<mizuiro::access::raw, mylib::native_format<Dim, Type>, Constness> const _pointer2)
{
  return _pointer1 - _pointer2;
}

}

namespace stride_ns
{

template <typename Dim, typename Type>
// NOLINTNEXTLINE(misc-use-internal-linkage)
mizuiro::size_type stride_adl(
    mizuiro::image::access::stride_ns::tag,
    mizuiro::access::raw const &,
    mylib::tag<mylib::native_format<Dim, Type>>,
    mizuiro::image::format::store<mylib::native_format<Dim, Type>> const &)
{
  return sizeof(Type);
}

}

namespace dereference_ns
{

template <typename Dim, typename Type>
mizuiro::image::types::
    reference<mizuiro::access::raw, mylib::native_format<Dim, Type>, mizuiro::nonconst_tag>
    // NOLINTNEXTLINE(misc-use-internal-linkage)
    dereference_adl(
        mizuiro::image::access::dereference_ns::tag,
        mizuiro::access::raw,
        mylib::tag<mylib::native_format<Dim, Type>>,
        mizuiro::nonconst_tag,
        mizuiro::image::format::store<mylib::native_format<Dim, Type>> const &,
        mizuiro::image::types::pointer<
            mizuiro::access::raw,
            mylib::native_format<Dim, Type>,
            mizuiro::nonconst_tag> const _data)
{
  return mizuiro::image::types::
      reference<mizuiro::access::raw, mylib::native_format<Dim, Type>, mizuiro::nonconst_tag>(
          _data);
}

}
}
}

namespace
{
namespace mylib
{

template <typename Type>
class proxy
{
public:
  using pointer = mizuiro::raw_pointer;

  explicit proxy(pointer const _data) : data_(_data) {}

  using value_type = Type;

FCPPT_PP_PUSH_WARNING
FCPPT_PP_IGNORE_UNSAFE_BUFFER_USAGE_IN_LIBC_CALL
  // NOLINTNEXTLINE(google-explicit-constructor,hicpp-explicit-conversions)
  operator value_type() const
  {
    value_type result;

    std::memcpy(&result, data_, sizeof(value_type));

    return result;
  }

  proxy &operator=(value_type const &_value)
  {
    std::memcpy(data_, &_value, sizeof(value_type));

    return *this;
  }

FCPPT_PP_POP_WARNING
private:
  pointer data_;
};

}
}

int main()
{
  using value_type = unsigned;

  using dim2 = mizuiro::image::dimension<2>;

  using native_view = mizuiro::image::linear_view<
      ::mizuiro::access::raw,
      mylib::native_format<dim2, value_type>,
      mizuiro::nonconst_tag>;

  using raw_vector = std::vector<mizuiro::raw_value>;

  dim2 const size(
      100U, // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
      50U // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
  );

  raw_vector data(sizeof(value_type) * mizuiro::image::dimension_content(size));

  native_view const view(size, data.data());

  for (native_view::iterator it(view.begin()); it != view.end(); ++it)
  {
    *it = static_cast<value_type>(std::distance(view.begin(), it));
  }

  mizuiro::image::algorithm::print(std::cout, view);

  std::cout << '\n';
}
