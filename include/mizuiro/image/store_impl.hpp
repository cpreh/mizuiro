//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_STORE_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_STORE_IMPL_HPP_INCLUDED

#include <mizuiro/image/store_decl.hpp>
#include <mizuiro/image/view_impl.hpp>
#include <mizuiro/image/access/store_size.hpp>
#include <mizuiro/image/detail/raw_container_impl.hpp>


template<
	typename Format
>
mizuiro::image::store<
	Format
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
	typename Format
>
mizuiro::image::store<
	Format
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
		mizuiro::image::access::store_size(
			_format,
			size_
		)
	)
{
}

template<
	typename Format
>
typename
mizuiro::image::store<
	Format
>::pointer
mizuiro::image::store<
	Format
>::data()
{
	return
		data_.data();
}

template<
	typename Format
>
typename
mizuiro::image::store<
	Format
>::const_pointer
mizuiro::image::store<
	Format
>::data() const
{
	return
		data_.data();
}

template<
	typename Format
>
typename
mizuiro::image::store<
	Format
>::view_type const
mizuiro::image::store<
	Format
>::view()
{
	return
		view_type(
			this->size(),
			this->data(),
			this->format_store_base()
		);
}

template<
	typename Format
>
typename
mizuiro::image::store<
	Format
>::const_view_type const
mizuiro::image::store<
	Format
>::view() const
{
	return
		const_view_type(
			this->size(),
			this->data(),
			this->format_store_base()
		);
}
template<
	typename Format
>
typename
mizuiro::image::store<
	Format
>::dim const &
mizuiro::image::store<
	Format
>::size() const
{
	return
		size_;
}

#endif
