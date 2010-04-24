#ifndef MIZUIRO_IMAGE_MAKE_RAW_VIEW_HPP_INCLUDED
#define MIZUIRO_IMAGE_MAKE_RAW_VIEW_HPP_INCLUDED

#include <mizuiro/image/detail/raw_view_from_pointer.hpp>
#include <mizuiro/image/raw_view.hpp>
#include <mizuiro/image/view_impl.hpp>
#include <mizuiro/is_raw_pointer.hpp>
#include <boost/utility/enable_if.hpp>

namespace mizuiro
{
namespace image
{

template<
	typename Format,
	typename Pointer
>
typename boost::enable_if<
	is_raw_pointer<
		Pointer
	>,
	typename detail::raw_view_from_pointer<
		Format,
		Pointer
	>::type
>::type const
make_raw_view(
	Pointer const data,
	typename detail::raw_view_from_pointer<
		Format,
		Pointer
	>::type::dim_type const &dim,
	typename detail::raw_view_from_pointer<
		Format,
		Pointer
	>::type::pitch_type const &pitch
)
{
	return
		typename detail::raw_view_from_pointer<
			Format,
			Pointer
		>::type(
			dim,
			data,
			pitch
		);
}

}
}

#endif
