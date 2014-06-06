//          Compareright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or compare at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_DETAIL_COMPARE_ELEMENT_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_DETAIL_COMPARE_ELEMENT_HPP_INCLUDED

#include <mizuiro/color/compare.hpp>
#include <mizuiro/detail/nonassignable.hpp>


namespace mizuiro
{
namespace image
{
namespace algorithm
{
namespace detail
{

template<
	typename Function
>
class compare_element
{
	MIZUIRO_DETAIL_NONASSIGNABLE(
		compare_element
	);
public:
	explicit
	compare_element(
		Function const &_function
	)
	:
		function_(
			_function
		)
	{
	}

	typedef
	bool
	result_type;

	template<
		typename Src1,
		typename Src2
	>
	result_type
	operator()(
		bool const _state,
		Src1 const &_src1,
		Src2 const &_src2
	) const
	{
		return
			_state
			&&
			mizuiro::color::compare(
				_src1,
				_src2,
				function_
			);
	}
private:
	Function const &function_;
};

}
}
}
}

#endif
