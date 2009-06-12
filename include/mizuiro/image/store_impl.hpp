#ifndef MIZUIRO_IMAGE_STORE_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_STORE_IMPL_HPP_INCLUDED

#include <mizuiro/image/store_decl.hpp>

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
	)
{}

template<
	typename Format
>
void
mizuiro::image::store<Format>::resize(
	dim_type const &ndim
)
{
	dim_ = ndim;
	data_.resize(
		dim_.content()
	);
}

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
		data()
	);
}

template<
	typename Format
>
typename mizuiro::image::store<Format>::const_view_type
mizuiro::image::store<Format>::view() const
{
	return const_view_type(
		dim(),
		data()
	);
}

#endif
