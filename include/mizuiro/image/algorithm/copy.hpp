#ifndef MIZUIRO_IMAGE_ALGORITHM_COPY_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_COPY_HPP_INCLUDED

#include <mizuiro/image/algorithm/detail/copy_impl.hpp>
#include <mizuiro/image/views_are_compatible.hpp>
#include <boost/static_assert.hpp>

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
void
copy(
	ViewS const &src,
	ViewD const &dest
)
{
	BOOST_STATIC_ASSERT((
		views_are_compatible<
			ViewS,
			ViewD
		>::value
	));

	detail::copy_impl(
		src,
		dest
	);
}

}
}
}

#endif
