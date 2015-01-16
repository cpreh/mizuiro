//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_FILL_INDEXED_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_FILL_INDEXED_HPP_INCLUDED

#include <mizuiro/image/algorithm/make_iterator_indexed.hpp>
#include <mizuiro/image/algorithm/unary_iteration.hpp>
#include <mizuiro/image/algorithm/detail/fill_indexed.hpp>


namespace mizuiro
{
namespace image
{
namespace algorithm
{

template<
	typename ViewD,
	typename Fun
>
void
fill_indexed(
	ViewD const &_dest,
	Fun const &_fun
)
{
	mizuiro::image::algorithm::unary_iteration(
		mizuiro::image::algorithm::detail::fill_indexed<
			Fun
		>(
			_fun
		),
		_dest,
		mizuiro::image::algorithm::make_iterator_indexed()
	);
}

}
}
}

#endif
