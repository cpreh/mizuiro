#ifndef MIZUIRO_IMAGE_ALGORITHM_DETAIL_COPY_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_DETAIL_COPY_IMPL_HPP_INCLUDED

#include <mizuiro/image/algorithm/detail/apply_binary_iteration.hpp>
#include <mizuiro/image/algorithm/detail/copy_element.hpp>
#include <mizuiro/image/algorithm/detail/copy_raw.hpp>
#include <mizuiro/image/views_have_same_channel_order.hpp>
#include <fcppt/variant/apply_binary.hpp>
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
	views_have_same_channel_order<
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
	fcppt::variant::apply_binary(
		apply_binary_iteration(
			detail::copy_element()
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
	views_have_same_channel_order<
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
	fcppt::variant::apply_binary(
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
