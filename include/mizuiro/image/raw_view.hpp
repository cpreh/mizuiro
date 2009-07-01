#ifndef MIZUIRO_IMAGE_RAW_VIEW_HPP_INCLUDED
#define MIZUIRO_IMAGE_RAW_VIEW_HPP_INCLUDED

#include <mizuiro/image/detail/raw_view.hpp>
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
typename detail::raw_view<
	iterator,
	Format,
	Pointer
>::type const
raw_view(
	Pointer const data,
	Dim const &dim,
	typename detail::pitch_type<
		Dim
	>::type const &pitch
)
{
	return typename detail::raw_view<
		iterator,
		Format,
		Pointer
	>(
		dim,
		data,
		data,
		pitch
	);
}

template<
	typename Format,
	typename Pointer,
	typename Dim
>
typename detail::raw_view<
	linear_iterator,
	Format,
	Pointer
> const
raw_view(
	Pointer const data,
	Dim const &dim
)
{
//	return view<>;
}

}
}

#endif
