//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERT_DETAIL_CHANNEL_TO_MAX_FUNCTOR_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERT_DETAIL_CHANNEL_TO_MAX_FUNCTOR_HPP_INCLUDED

#include <mizuiro/color/convert/detail/channel_to_max.hpp>
#include <mizuiro/detail/nonassignable.hpp>

namespace mizuiro
{
namespace color
{
namespace detail
{

template<
	typename Dest
>
class channel_to_max_functor
{
	MIZUIRO_DETAIL_NONASSIGNABLE(
		channel_to_max_functor
	);
public:
	explicit channel_to_max_functor(
		Dest &_dest
	)
	:
		dest_(_dest)
	{
	}

	typedef void result_type;

	template<
		typename Channel
	>
	result_type
	operator()(
		Channel const &
	) const
	{
		detail::channel_to_max<
			Channel
		>(
			dest_
		);
	}
private:
	Dest &dest_;
};

}
}
}

#endif
