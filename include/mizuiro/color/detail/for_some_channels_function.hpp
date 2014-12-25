//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_DETAIL_FOR_SOME_CHANNELS_FUNCTION_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_FOR_SOME_CHANNELS_FUNCTION_HPP_INCLUDED

#include <mizuiro/detail/nonassignable.hpp>


namespace mizuiro
{
namespace color
{
namespace detail
{

template<
	typename Function,
	typename Filter
>
class for_some_channels_function
{
	MIZUIRO_DETAIL_NONASSIGNABLE(
		for_some_channels_function
	);
public:
	for_some_channels_function(
		Function const &_function,
		Filter const &_filter
	)
	:
		function_(
			_function
		),
		filter_(
			_filter
		)
	{
	}

	typedef
	void
	result_type;

	template<
		typename T
	>
	result_type
	operator()(
		T const &_value
	) const
	{
		if(
			filter_(
				_value
			)
		)
			function_(
				_value
			);
	}
private:
	Function const function_;

	Filter const filter_;
};

}
}
}

#endif
