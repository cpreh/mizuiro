//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_DETAIL_PRINT_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_DETAIL_PRINT_HPP_INCLUDED

#include <mizuiro/color/output.hpp>

namespace mizuiro
{
namespace image
{
namespace algorithm
{
namespace detail
{

template<
	typename Sink
>
struct print {
	typedef void result_type;

	explicit print(
		Sink &sink
	)
	:
		sink(sink)
	{}

	template<
		typename Src
	>
	result_type
	operator()(
		Src const &src
	) const
	{
		sink
			<< src
			<< sink.widen(' ');
	}
private:
	Sink &sink;
};

}
}
}
}

#endif
