//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_DETAIL_COPY_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_COPY_CHANNEL_HPP_INCLUDED

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
struct copy_channel
{
	typedef void result_type;

	copy_channel(
		Dest const &dest,
		Src const &src
	)
	:
		dest(dest),
		src(src)
	{}

	template<
		typename Channel
	>
	result_type
	operator()(
		Channel &
	) const
	{
		dest. template set<
			Channel
		>(
			src. template get<
				Channel
			>()
		);
	}
private:
	Dest const &dest;
	Src const &src;
};

}
}
}

#endif
