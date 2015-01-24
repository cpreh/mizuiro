//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_FILL_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_FILL_HPP_INCLUDED

#include <mizuiro/image/algorithm/for_each.hpp>
#include <mizuiro/image/algorithm/make_iterator_identity.hpp>
#include <mizuiro/image/algorithm/uninitialized.hpp>
#include <mizuiro/image/algorithm/detail/fill.hpp>


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
inline
void
fill(
	ViewD const &_dest,
	Fun const &_fun,
	mizuiro::image::algorithm::uninitialized const _uninitialized
)
{
	mizuiro::image::algorithm::for_each(
		_dest,
		mizuiro::image::algorithm::detail::fill<
			Fun
		>(
			_fun
		),
		mizuiro::image::algorithm::make_iterator_identity{},
		_uninitialized
	);
}

}
}
}

#endif
