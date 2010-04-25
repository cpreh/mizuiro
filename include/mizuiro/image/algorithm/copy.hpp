#ifndef MIZUIRO_IMAGE_ALGORITHM_COPY_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_COPY_HPP_INCLUDED

#include <mizuiro/image/algorithm/detail/copy_impl.hpp>
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
typename boost::enable_if<
	views_are_compatible<
		ViewS,
		ViewD
	>,
	void
>::type
copy(
	ViewS const &src,
	ViewD const &dest
)
{
	detail::copy_impl(
		src,
		dest
	);
}

}
}
}

#endif
