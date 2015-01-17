//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_STORE_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_STORE_IMPL_HPP_INCLUDED

#include <mizuiro/empty.hpp>
#include <mizuiro/no_init.hpp>
#include <mizuiro/image/dimension_impl.hpp>
#include <mizuiro/image/linear_view_impl.hpp>
#include <mizuiro/image/store_decl.hpp>
#include <mizuiro/image/access/store_size.hpp>
#include <mizuiro/image/algorithm/fill_c.hpp>


template<
	typename Format,
	typename Access
>
mizuiro::image::store<
	Format,
	Access
>::store(
	dim const &_size,
	mizuiro::no_init const &,
	format_store_type const &_format
)
:
	format_base(
		_format
	),
	size_(
		_size
	),
	// FIXME: Stores must be initialized for some formats
	data_(
		mizuiro::image::access::store_size<
			access
		>(
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
mizuiro::image::store<
	Format,
	Access
>::store(
	mizuiro::empty const &,
	format_store_type const &_format
)
:
	store(
		dim::null(),
		mizuiro::no_init{},
		_format
	)
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
	value_type const &_init,
	format_store_type const &_format
)
:
	store(
		_size,
		mizuiro::no_init{},
		_format
	)
{
	mizuiro::image::algorithm::fill_c(
		this->view(),
		_init
	);
}

template<
	typename Format,
	typename Access
>
template<
	typename Function
>
mizuiro::image::store<
	Format,
	Access
>::store(
	dim const &_size,
	Function const &_function,
	format_store_type const &_format
)
:
	store(
		_size,
		mizuiro::no_init{},
		_format
	)
{
	_function(
		this->view()
	);
}

template<
	typename Format,
	typename Access
>
typename
mizuiro::image::store<
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
typename
mizuiro::image::store<
	Format,
	Access
>::const_pointer
mizuiro::image::store<
	Format,
	Access
>::data() const
{
	return
		data_.data();
}

template<
	typename Format,
	typename Access
>
typename
mizuiro::image::store<
	Format,
	Access
>::view_type const
mizuiro::image::store<
	Format,
	Access
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
	typename Format,
	typename Access
>
typename
mizuiro::image::store<
	Format,
	Access
>::const_view_type const
mizuiro::image::store<
	Format,
	Access
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
	typename Format,
	typename Access
>
typename
mizuiro::image::store<
	Format,
	Access
>::dim const &
mizuiro::image::store<
	Format,
	Access
>::size() const
{
	return
		size_;
}

#endif
