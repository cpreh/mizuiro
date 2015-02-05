//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_ARRAY_INIT_EACH_RT_FUNCTION_HPP_INCLUDED
#define MIZUIRO_DETAIL_ARRAY_INIT_EACH_RT_FUNCTION_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <mizuiro/detail/nonassignable.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <type_traits>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace detail
{

template<
	typename Function
>
class array_init_each_rt_function
{
	MIZUIRO_DETAIL_NONASSIGNABLE(
		array_init_each_rt_function
	);
public:
	explicit
	array_init_each_rt_function(
		Function const &_function
	)
	:
		function_{
			_function
		}
	{
	}

	template<
		typename Index
	>
	typename
	std::result_of<
		Function(
			mizuiro::size_type
		)
	>::type
	operator()(
		Index
	) const
	{
		return
			function_(
				Index::value
			);
	}
private:
	Function const function_;
};

}
}

#endif
