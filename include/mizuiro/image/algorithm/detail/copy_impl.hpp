//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_DETAIL_COPY_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_DETAIL_COPY_IMPL_HPP_INCLUDED

#include <mizuiro/image/algorithm/detail/apply_binary_iteration.hpp>
#include <mizuiro/image/algorithm/detail/copy_element.hpp>
#include <mizuiro/image/algorithm/detail/copy_raw.hpp>
#include <mizuiro/image/views_have_same_channel_order.hpp>
#include <mizuiro/detail/variant_apply_binary.hpp>
#include <boost/utility/enable_if.hpp>

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
	ViewS const &src,
	ViewD const &dest
)
{
	mizuiro::detail::variant_apply_binary(
		algorithm::detail::apply_binary_iteration(
			algorithm::detail::copy_element()
		),
		src.range(),
		dest.range()
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
	ViewS const &src,
	ViewD const &dest
)
{
	mizuiro::detail::variant_apply_binary(
		copy_raw(),
		src.range(),
		dest.range()
	);
}

}
}
}
}

#endif
