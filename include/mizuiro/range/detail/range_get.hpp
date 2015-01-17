//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_RANGE_DETAIL_RANGE_GET_HPP_INCLUDED
#define MIZUIRO_RANGE_DETAIL_RANGE_GET_HPP_INCLUDED

#include <mizuiro/detail/nonassignable.hpp>


namespace mizuiro
{
namespace range
{
namespace detail
{

template<
	typename Function
>
class range_get
{
	MIZUIRO_DETAIL_NONASSIGNABLE(
		range_get
	);
public:
	explicit
	range_get(
		Function const &_function
	)
	:
		function_(
			_function
		)
	{
	}

	template<
		typename Range
	>
	void
	operator()(
		Range const &_range
	) const
	{
		function_(
			_range.get()
		);
	}
private:
	Function const &function_;
};

}
}
}

#endif
