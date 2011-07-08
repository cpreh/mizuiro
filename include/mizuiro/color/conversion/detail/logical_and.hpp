//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERSION_DETAIL_LOGICAL_AND_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERSION_DETAIL_LOGICAL_AND_HPP_INCLUDED

#include <mizuiro/detail/nonassignable.hpp>

namespace mizuiro
{
namespace color
{
namespace conversion
{
namespace detail
{

template<
	typename Fun1,
	typename Fun2
>
class logical_and
{
	MIZUIRO_DETAIL_NONASSIGNABLE(
		logical_and
	);
public:
	typedef bool result_type;

	logical_and(
		Fun1 const &_fun1,
		Fun2 const &_fun2
	)
	:
		fun1_(_fun1),
		fun2_(_fun2)
	{
	}

	template<
		typename T
	>
	bool
	operator()(
		T const &_value
	) const
	{
		return
			fun1_(
				_value
			)
			&&
			fun2_(
				_value
			);
	}
private:
	Fun1 const fun1_;

	Fun2 const fun2_;
};

}
}
}
}

#endif
