//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_INIT_DETAIL_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_INIT_DETAIL_CHANNEL_HPP_INCLUDED

#include <mizuiro/color/init/detail/channel_fwd.hpp>
#include <mizuiro/color/init/detail/make_impl.hpp>
#include <boost/fusion/container/vector/vector.hpp>
#include <boost/fusion/container/generation/make_vector.hpp>

namespace mizuiro
{
namespace color
{
namespace init
{
namespace detail
{

template<
	typename Value,
	typename Channel
>
class channel
{
public:
	typedef Value value_type;
	typedef Channel channel_type;

	explicit channel(
		Value const &value_
	)
	:
		value_(value_)
	{}
	
	Value const &
	value() const
	{
		return value_;
	}

	template<
		typename NewInit
	>
	make_impl<
		boost::fusion::vector2<
			detail::channel<
				Value,
				Channel
			>,
			NewInit
		>
	> const
	operator()(
		NewInit const &_newinit
	) const
	{
		return
			boost::fusion::make_vector(
				*this,
				_newinit
			);
	}
private:
	Value const value_;
};

}
}
}
}

#endif
