//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_STORE_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_STORE_IMPL_HPP_INCLUDED

#include <mizuiro/image/store_decl.hpp>
#include <mizuiro/image/view_impl.hpp>
#include <mizuiro/image/access/data_store_size.hpp>
#include <mizuiro/image/detail/raw_container_impl.hpp>


template<
	typename Format,
	typename Access
>
mizuiro::image::store<
	Format,
	Access
>::store(
	format_store_type const &_format
)
:
	format_base(
		_format
	),
	size_(
		dim::null()
	),
	data_()
{
}

template<
	typename Format,
	typename Access
>
mizuiro::image::store<
	Format,
	Access
>::store(
	dim const &_size,
	format_store_type const &_format
)
:
	format_base(
		_format
	),
	size_(
		_size
	),
	data_(
		mizuiro::image::access::data_store_size<
			Access,
			Format
		>::execute(
			Access(),
			_format,
			size_
		)
	)
{
}

template<
	typename Format,
	typename Access
>
typename mizuiro::image::store<
	Format,
	Access
>::pointer
mizuiro::image::store<
	Format,
	Access
>::data()
{
	return
		data_.data();
}

template<
	typename Format,
	typename Access
>
typename mizuiro::image::store<Format, Access>::const_pointer
mizuiro::image::store<Format, Access>::data() const
{
	return data_.data();
}

template<
	typename Format,
	typename Access
>
typename mizuiro::image::store<Format, Access>::view_type const
mizuiro::image::store<Format, Access>::view()
{
	return
		view_type(
			this->size(),
			this->data(),
			this->format_store_base()
		);
}

template<
	typename Format,
	typename Access
>
typename mizuiro::image::store<Format, Access>::const_view_type const
mizuiro::image::store<Format, Access>::view() const
{
	return
		const_view_type(
			this->size(),
			this->data(),
			this->format_store_base()
		);
}
template<
	typename Format,
	typename Access
>
typename mizuiro::image::store<Format, Access>::dim const &
mizuiro::image::store<Format, Access>::size() const
{
	return size_;
}

#endif
