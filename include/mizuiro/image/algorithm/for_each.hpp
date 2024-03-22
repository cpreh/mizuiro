//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_ALGORITHM_FOR_EACH_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_FOR_EACH_HPP_INCLUDED

#include <mizuiro/image/algorithm/unary_iteration.hpp>
#include <mizuiro/image/algorithm/uninitialized.hpp>
#include <mizuiro/image/algorithm/detail/wrap_prepare.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>

namespace mizuiro::image::algorithm
{

template <typename View, typename Function, typename MakeIterator>
inline void for_each(
    View const &_view,
    Function const &_function,
    MakeIterator const _make_iterator,
    mizuiro::image::algorithm::uninitialized const _uninitialized)
{
  FCPPT_PP_PUSH_WARNING
  FCPPT_PP_DISABLE_GCC_WARNING(-Wswitch-default)
  switch (_uninitialized)
  {
  case mizuiro::image::algorithm::uninitialized::yes:
    mizuiro::image::algorithm::unary_iteration(
        mizuiro::image::algorithm::detail::
            wrap_prepare<typename View::access, typename View::format>(
                _view.format_store(), _function),
        _view,
        _make_iterator);
    return;
  case mizuiro::image::algorithm::uninitialized::no:
    mizuiro::image::algorithm::unary_iteration(_function, _view, _make_iterator);
    return;
  }
  FCPPT_PP_POP_WARNING
}

}

#endif
