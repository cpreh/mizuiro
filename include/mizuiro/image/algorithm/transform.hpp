//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_TRANSFORM_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_TRANSFORM_HPP_INCLUDED

#include <mizuiro/image/algorithm/binary_iteration.hpp>
#include <mizuiro/image/algorithm/uninitialized.hpp>
#include <mizuiro/image/algorithm/detail/wrap_prepare.hpp>


namespace mizuiro::image::algorithm
{

template<
	typename ViewS,
	typename ViewD,
	typename Fun,
	typename MakeIterator
>
inline
void
transform(
	ViewS const &_source,
	ViewD const &_dest,
	Fun const &_fun,
	MakeIterator const _make_iterator,
	mizuiro::image::algorithm::uninitialized const _uninitialized
)
{
	switch(
		_uninitialized
	)
	{
	case mizuiro::image::algorithm::uninitialized::yes:
		mizuiro::image::algorithm::binary_iteration(
			mizuiro::image::algorithm::detail::wrap_prepare<
				typename
				ViewD::access,
				typename
				ViewD::format
			>(
				_dest.format_store(),
				_fun
			),
			_source,
			_dest,
			_make_iterator
		);
		return;
	case mizuiro::image::algorithm::uninitialized::no:
		mizuiro::image::algorithm::binary_iteration(
			_fun,
			_source,
			_dest,
			_make_iterator
		);
		return;
	}
}

}

#endif
