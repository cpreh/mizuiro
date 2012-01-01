//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_DETAIL_FOR_SOME_CHANNELS_FUNCTOR_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_FOR_SOME_CHANNELS_FUNCTOR_HPP_INCLUDED

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
class for_some_channels_functor
{
	MIZUIRO_DETAIL_NONASSIGNABLE(
		for_some_channels_functor
	);
public:
	for_some_channels_functor(
		Function const &_functor,
		Filter const &_filter
	)
	:
		functor_(_functor),
		filter_(_filter)
	{
	}

	typedef void result_type;

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
			functor_(
				_value
			);
	}
private:
	Function const functor_;

	Filter const filter_;
};

}
}
}

#endif
