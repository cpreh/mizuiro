//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_ALGORITHM_DETAIL_ITERATION_TO_FOLD_FUNCTION_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_DETAIL_ITERATION_TO_FOLD_FUNCTION_HPP_INCLUDED

#include <mizuiro/image/algorithm/detail/dummy_state.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace mizuiro::image::algorithm::detail
{

template <typename Function>
class iteration_to_fold_function
{
public:
  explicit iteration_to_fold_function(Function const &_function) : function_(_function) {}

  template <typename... Args>
  mizuiro::image::algorithm::detail::dummy_state
  operator()(mizuiro::image::algorithm::detail::dummy_state, Args &&..._args) const
  {
    function_.get()(std::forward<Args>(_args)...);

    return {};
  }

private:
  fcppt::reference<Function const> function_;
};

}

#endif
