//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_DETAIL_FILL_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_DETAIL_FILL_HPP_INCLUDED

namespace mizuiro
{
namespace image
{
namespace algorithm
{
namespace detail
{

template<
	typename Fun
>
struct fill {
	typedef void result_type;

	explicit fill(
		Fun const &fun
	)
	:
		fun(fun)
	{}

	template<
		typename Dest
	>
	result_type
	operator()(
		Dest const &dest
	) const
	{
		dest = fun();
	}
private:
	Fun const &fun;
};

}
}
}
}

#endif
