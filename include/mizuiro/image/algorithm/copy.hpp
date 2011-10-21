//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_COPY_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_COPY_HPP_INCLUDED

#include <mizuiro/image/views_are_compatible.hpp>
#include <mizuiro/image/algorithm/may_overlap.hpp>
#include <mizuiro/image/algorithm/detail/copy_impl.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <mizuiro/detail/external_end.hpp>


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
typename boost::enable_if<
	image::views_are_compatible<
		ViewS,
		ViewD
	>,
	void
>::type
copy(
	ViewS const &_src,
	ViewD const &_dest,
	algorithm::may_overlap::type const _overlap
)
{
	detail::copy_impl(
		_src,
		_dest,
		_overlap
	);
}

}
}
}

#endif
