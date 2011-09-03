//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_DETAIL_COPY_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_DETAIL_COPY_IMPL_HPP_INCLUDED

#include <mizuiro/image/algorithm/copy_different_channel_order.hpp>
#include <mizuiro/image/algorithm/copy_same_channel_order.hpp>
#include <mizuiro/image/algorithm/may_overlap.hpp>
#include <mizuiro/image/views_have_same_channel_order.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <mizuiro/detail/external_end.hpp>

namespace mizuiro
{
namespace image
{
namespace algorithm
{
namespace detail
{

template<
	typename ViewS,
	typename ViewD
>
typename boost::disable_if<
	mizuiro::image::views_have_same_channel_order<
		ViewS,
		ViewD
	>,
	void
>::type
copy_impl(
	ViewS const &_src,
	ViewD const &_dest,
	algorithm::may_overlap::type const _overlap
)
{
	algorithm::copy_different_channel_order(
		_src,
		_dest,
		_overlap
	);
}

template<
	typename ViewS,
	typename ViewD
>
typename boost::enable_if<
	mizuiro::image::views_have_same_channel_order<
		ViewS,
		ViewD
	>,
	void
>::type
copy_impl(
	ViewS const &_src,
	ViewD const &_dest,
	algorithm::may_overlap::type const _overlap
)
{
	algorithm::copy_same_channel_order(
		_src,
		_dest,
		_overlap
	);
}

}
}
}
}

#endif
