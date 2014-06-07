//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_DETAIL_COPY_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_COPY_CHANNEL_HPP_INCLUDED

#include <mizuiro/detail/nonassignable.hpp>


namespace mizuiro
{
namespace color
{
namespace detail
{

template<
	typename Dest,
	typename Src
>
class copy_channel
{
	MIZUIRO_DETAIL_NONASSIGNABLE(
		copy_channel
	);
public:
	typedef void result_type;

	copy_channel(
		Dest const &_dest,
		Src const &_src
	)
	:
		dest_(
			_dest
		),
		src_(
			_src
		)
	{
	}

	template<
		typename Channel
	>
	result_type
	operator()(
		Channel const &_channel
	) const
	{
		dest_.set(
			_channel,
			src_.get(
				_channel
			)
		);
	}
private:
	Dest const &dest_;

	Src const &src_;
};

}
}
}

#endif
