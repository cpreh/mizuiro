//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_COPY_AND_CONVERT_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_COPY_AND_CONVERT_HPP_INCLUDED

#include <mizuiro/image/algorithm/detail/copy_and_convert.hpp>
#include <mizuiro/image/algorithm/binary_iteration.hpp>
#include <mizuiro/image/algorithm/copy.hpp>
#include <mizuiro/image/algorithm/may_overlap.hpp>
#include <mizuiro/image/views_are_compatible.hpp>
#include <boost/utility/enable_if.hpp>

namespace mizuiro
{
namespace image
{
namespace algorithm
{

template<
	typename ViewS,
	typename ViewD
>
typename boost::disable_if<
	image::views_are_compatible<
		ViewS,
		ViewD
	>,
	void
>::type
copy_and_convert(
	ViewS const &_src,
	ViewD const &_dest,
	algorithm::may_overlap::type
)
{
	algorithm::binary_iteration(
		detail::copy_and_convert(),
		_src,
		_dest
	);
}

template<
	typename ViewS,
	typename ViewD
>
typename boost::enable_if<
	image::views_are_compatible<
		ViewS,
		ViewD
	>,
	void
>::type
copy_and_convert(
	ViewS const &_src,
	ViewD const &_dest,
	algorithm::may_overlap::type const _overlap
)
{
	algorithm::copy(
		_src,
		_dest,
		_overlap
	);
}

}
}
}

#endif
