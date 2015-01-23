//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_FILL_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_FILL_HPP_INCLUDED

#include <mizuiro/image/algorithm/make_iterator_identity.hpp>
#include <mizuiro/image/algorithm/unary_iteration.hpp>
#include <mizuiro/image/algorithm/uninitialized.hpp>
#include <mizuiro/image/algorithm/detail/fill.hpp>
#include <mizuiro/image/algorithm/detail/wrap_prepare.hpp>


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
	mizuiro::image::algorithm::detail::fill<
		Fun
	> const function(
		_fun
	);

	mizuiro::image::algorithm::make_iterator_identity make_iterator;

	switch(
		_uninitialized
	)
	{
	case mizuiro::image::algorithm::uninitialized::yes:
		mizuiro::image::algorithm::unary_iteration(
			mizuiro::image::algorithm::detail::wrap_prepare<
				typename
				ViewD::access
			>(
				_dest.format_store(),
				function
			),
			_dest,
			make_iterator
		);
		return;
	case mizuiro::image::algorithm::uninitialized::no:
		mizuiro::image::algorithm::unary_iteration(
			function,
			_dest,
			make_iterator
		);
		return;
	}
}

}
}
}

#endif
