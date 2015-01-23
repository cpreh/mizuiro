//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_COPY_AND_CONVERT_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_COPY_AND_CONVERT_HPP_INCLUDED

#include <mizuiro/image/algorithm/can_copy.hpp>
#include <mizuiro/image/algorithm/copy.hpp>
#include <mizuiro/image/algorithm/may_overlap.hpp>
#include <mizuiro/image/algorithm/transform.hpp>
#include <mizuiro/image/algorithm/uninitialized.hpp>
#include <mizuiro/image/algorithm/detail/copy_and_convert.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <type_traits>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace image
{
namespace algorithm
{

template<
	typename Converter,
	typename ViewS,
	typename ViewD
>
inline
typename
std::enable_if<
	!mizuiro::image::algorithm::can_copy<
		ViewS,
		ViewD
	>::value,
	void
>::type
copy_and_convert(
	ViewS const &_src,
	ViewD const &_dest,
	mizuiro::image::algorithm::may_overlap,
	mizuiro::image::algorithm::uninitialized const _uninitialized
)
{
	mizuiro::image::algorithm::transform(
		_src,
		_dest,
		mizuiro::image::algorithm::detail::copy_and_convert<
			Converter
		>{},
		_uninitialized
	);
}

template<
	typename Converter,
	typename ViewS,
	typename ViewD
>
inline
typename
std::enable_if<
	mizuiro::image::algorithm::can_copy<
		ViewS,
		ViewD
	>::value,
	void
>::type
copy_and_convert(
	ViewS const &_src,
	ViewD const &_dest,
	mizuiro::image::algorithm::may_overlap const _overlap,
	mizuiro::image::algorithm::uninitialized const _uninitialized
)
{
	mizuiro::image::algorithm::copy(
		_src,
		_dest,
		_overlap,
		_uninitialized
	);
}

}
}
}

#endif
