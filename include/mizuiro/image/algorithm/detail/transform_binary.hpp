//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_DETAIL_TRANSFORM_BINARY_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_DETAIL_TRANSFORM_BINARY_HPP_INCLUDED

#include <mizuiro/detail/nonassignable.hpp>

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
class transform_binary
{
	MIZUIRO_DETAIL_NONASSIGNABLE(
		transform_binary
	);
public:
	typedef void result_type;

	explicit transform_binary(
		Fun const &fun
	)
	:
		fun(fun)
	{}

	template<
		typename Source,
		typename Dest
	>
	result_type
	operator()(
		Source const &source,
		Dest const &dest
	) const
	{
		fun(
			source,
			dest
		);
	}
private:
	Fun const &fun;
};

}
}
}
}

#endif
