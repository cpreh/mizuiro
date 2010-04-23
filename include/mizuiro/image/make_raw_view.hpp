#ifndef MIZUIRO_IMAGE_MAKE_RAW_VIEW_HPP_INCLUDED
#define MIZUIRO_IMAGE_MAKE_RAW_VIEW_HPP_INCLUDED

#include <mizuiro/image/raw_view.hpp>
#include <mizuiro/image/const_view.hpp>
#include <mizuiro/image/iterator_impl.hpp>
#include <mizuiro/image/linear_iterator_impl.hpp>
#include <mizuiro/raw_pointer.hpp>
#include <mizuiro/const_raw_pointer.hpp>

namespace mizuiro
{
namespace image
{

// TODO: make this work with const_raw_pointer, too!

template<
	typename Format
>
typename raw_view<
	Format
>::type const
make_raw_view(
	raw_pointer const data,
	typename raw_view<
		Format
	>::type::dim_type const &dim,
	typename raw_view<
		Format
	>::type::pitch_type const &pitch
)
{
	return typename raw_view<
		Format
	>::type(
		dim,
		data,
		pitch
	);
}

template<
	typename Format
>
typename const_view<
	typename raw_view<
		Format
	>::type
>::type const
make_raw_view(
	const_raw_pointer const data,
	typename raw_view<
		Format
	>::type::dim_type const &dim,
	typename raw_view<
		Format
	>::type::pitch_type const &pitch
)
{
	return typename const_view<
		typename raw_view<
			Format
		>::type
	>::type(
		dim,
		data,
		pitch
	);
}


}
}

#endif
