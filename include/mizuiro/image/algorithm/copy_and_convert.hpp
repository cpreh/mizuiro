#ifndef MIZUIRO_IMAGE_ALGORITHM_COPY_AND_CONVERT_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_COPY_AND_CONVERT_HPP_INCLUDED

#include <mizuiro/image/algorithm/detail/apply_binary_iteration.hpp>
#include <mizuiro/image/algorithm/detail/copy_and_convert.hpp>
#include <mizuiro/image/algorithm/copy.hpp>
#include <mizuiro/image/views_are_compatible.hpp>
#include <fcppt/variant/apply_binary.hpp>
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
	views_are_compatible<
		ViewS,
		ViewD
	>,
	void
>::type
copy_and_convert(
	ViewS const &src,
	ViewD const &dest
)
{
	fcppt::variant::apply_binary(
		detail::apply_binary_iteration(
			detail::copy_and_convert()
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
	views_are_compatible<
		ViewS,
		ViewD
	>,
	void
>::type
copy_and_convert(
	ViewS const &src,
	ViewD const &dest
)
{
	algorithm::copy(
		src,
		dest
	);
}

}
}
}

#endif
