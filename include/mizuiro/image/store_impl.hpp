#ifndef MIZUIRO_IMAGE_STORE_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_STORE_IMPL_HPP_INCLUDED

#include <mizuiro/image/store_decl.hpp>
#include <mizuiro/image/detail/raw_container_impl.hpp>

template<
	typename Format
>
mizuiro::image::store<Format>::store()
:
	dim_(
		dim_type::null()
	),
	data_()
{}

template<
	typename Format
>
mizuiro::image::store<Format>::store(
	dim_type const &dim_
)
:
	dim_(
		dim_
	),
	data_(
		dim_.content()
		* Format::image_format::color_format::element_count
	)
{}

template<
	typename Format
>
typename mizuiro::image::store<Format>::pointer
mizuiro::image::store<Format>::data()
{
	return data_.data();
}

template<
	typename Format
>
typename mizuiro::image::store<Format>::const_pointer
mizuiro::image::store<Format>::data() const
{
	return data_.data();
}

template<
	typename Format
>
typename mizuiro::image::store<Format>::view_type const
mizuiro::image::store<Format>::view()
{
	return view_type(
		dim(),
		data(),
		view_type::pitch_type::null()
	);
}

template<
	typename Format
>
typename mizuiro::image::store<Format>::const_view_type const
mizuiro::image::store<Format>::view() const
{
	return const_view_type(
		dim(),
		data(),
		view_type::pitch_type::null()
	);
}
template<
	typename Format
>
typename mizuiro::image::store<Format>::dim_type const &
mizuiro::image::store<Format>::dim() const
{
	return dim_;
}

#endif
