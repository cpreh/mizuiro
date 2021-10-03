//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_CLONE_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_CLONE_HPP_INCLUDED

#include <mizuiro/image/store.hpp>
#include <mizuiro/image/algorithm/copy.hpp>
#include <mizuiro/image/algorithm/may_overlap.hpp>
#include <mizuiro/image/algorithm/uninitialized.hpp>


namespace mizuiro::image::algorithm
{

template<
	typename ViewS
>
mizuiro::image::store<
	typename ViewS::format,
	typename ViewS::access
>
clone(
	ViewS const &_src
)
{
	using
	result_type
	=
	mizuiro::image::store<
		typename ViewS::format,
		typename ViewS::access
	>;

	return
		result_type{
			_src.size(),
			[
				&_src
			](
				typename
				result_type::view_type const &_view
			)
			{
				mizuiro::image::algorithm::copy(
					_src,
					_view,
					mizuiro::image::algorithm::may_overlap::no,
					mizuiro::image::algorithm::uninitialized::yes
				);
			},
			_src.format_store()
		};
}

}

#endif
