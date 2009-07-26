#ifndef MIZUIRO_IMAGE_MAKE_RAW_VIEW_HPP_INCLUDED
#define MIZUIRO_IMAGE_MAKE_RAW_VIEW_HPP_INCLUDED

#include <mizuiro/image/raw_view.hpp>
#include <mizuiro/image/iterator_impl.hpp>
#include <mizuiro/image/linear_iterator_impl.hpp>

namespace mizuiro
{
namespace image
{

template<
	typename Format,
	typename Pointer,
	typename Dim
>
typename raw_view<
	Format,
	Pointer
>::type const
make_raw_view(
	Pointer const data,
	Dim const &dim,
	typename detail::pitch_type<
		Dim
	>::type const &pitch
)
{
	return typename raw_view<
		Format,
		Pointer
	>::type(
		dim,
		data,
		data,
		pitch
	);
}

}
}

#endif
