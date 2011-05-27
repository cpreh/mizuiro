//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERT_DETAIL_COPY_AND_CONVERT_CHANNEL_FUNCTOR_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERT_DETAIL_COPY_AND_CONVERT_CHANNEL_FUNCTOR_HPP_INCLUDED

#include <mizuiro/color/convert/detail/copy_and_convert_channel.hpp>
#include <mizuiro/color/normalize.hpp>
#include <mizuiro/color/denormalize.hpp>
#include <mizuiro/detail/nonassignable.hpp>

namespace mizuiro
{
namespace color
{
namespace detail
{

template<
	typename Src,
	typename Dest,
	typename Float
>
class copy_and_convert_channel_functor
{
	MIZUIRO_DETAIL_NONASSIGNABLE(
		copy_and_convert_channel_functor
	);
public:
	copy_and_convert_channel_functor(
		Src const &_src,
		Dest &_dest
	)
	:
		src_(_src),
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
		detail::copy_and_convert_channel<
			Channel,
			Float
		>(
			src_,
			dest_
		);
	}
private:
	Src const &src_;

	Dest &dest_;
};

}
}
}

#endif
