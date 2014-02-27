//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_DETAIL_PRINT_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_DETAIL_PRINT_HPP_INCLUDED

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
	typename Sink
>
class print
{
	MIZUIRO_DETAIL_NONASSIGNABLE(
		print
	);
public:
	typedef
	void
	result_type;

	explicit
	print(
		Sink &_sink
	)
	:
		sink_(
			_sink
		)
	{
	}

	template<
		typename Src
	>
	result_type
	operator()(
		Src const &_src
	) const
	{
		sink_
			<< _src
			<< sink_.widen(' ');
	}
private:
	Sink &sink_;
};

}
}
}
}

#endif
