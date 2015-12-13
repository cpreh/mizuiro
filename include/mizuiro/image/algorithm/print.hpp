//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_PRINT_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_PRINT_HPP_INCLUDED

#include <mizuiro/image/algorithm/make_iterator_identity.hpp>
#include <mizuiro/image/algorithm/unary_iteration.hpp>


namespace mizuiro
{
namespace image
{
namespace algorithm
{

template<
	typename Sink,
	typename ViewS
>
void
print(
	Sink &_sink,
	ViewS const &_src
)
{
	mizuiro::image::algorithm::unary_iteration(
		[
			&_sink
		](
			auto const &_src_inner
		)
		{
			_sink
				<< _src_inner
				<< _sink.widen(' ');
		},
		_src,
		mizuiro::image::algorithm::make_iterator_identity()
	);
}

}
}
}

#endif
