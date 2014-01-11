//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_DETAIL_RAW_CONTAINER_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_RAW_CONTAINER_IMPL_HPP_INCLUDED

#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/image/detail/raw_container_decl.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <memory>
#include <mizuiro/detail/external_end.hpp>


template<
	typename T,
	typename A
>
mizuiro::image::detail::raw_container<
	T,
	A
>::raw_container()
:
	allocator(),
	data_(
		nullptr
	),
	data_end_(
		nullptr
	)
{
}

MIZUIRO_DETAIL_IGNORE_EFFCPP

template<
	typename T,
	typename A
>
mizuiro::image::detail::raw_container<
	T,
	A
>::raw_container(
	size_type const _size
)
:
	allocator()
	// Dont' initialize data_ and data_end_
{
	this->allocate(
		_size
	);
}

template<
	typename T,
	typename A
>
mizuiro::image::detail::raw_container<
	T,
	A
>::raw_container(
	raw_container const &_other
)
:
	allocator()
	// Dont' initialize data_ and data_end_
{
	this->copy(
		_other
	);
}

MIZUIRO_DETAIL_POP_WARNING

template<
	typename T,
	typename A
>
mizuiro::image::detail::raw_container<
	T,
	A
>::raw_container(
	raw_container &&_other
)
:
	allocator(),
	data_(
		_other.data_
	),
	data_end_(
		_other.data_end_
	)
{
	_other.after_move();
}

template<
	typename T,
	typename A
>
mizuiro::image::detail::raw_container<
	T,
	A
> &
mizuiro::image::detail::raw_container<
	T,
	A
>::operator=(
	raw_container const &_other
)
{
	this->destroy();

	this->copy(
		_other
	);

	return
		*this;
}

template<
	typename T,
	typename A
>
mizuiro::image::detail::raw_container<
	T,
	A
> &
mizuiro::image::detail::raw_container<
	T,
	A
>::operator=(
	raw_container &&_other
)
{
	this->destroy();

	data_ =
		_other.data_;

	data_end_ =
		_other.data_end_;

	_other.after_move();

	return
		*this;
}

template<
	typename T,
	typename A
>
mizuiro::image::detail::raw_container<
	T,
	A
>::~raw_container()
{
	this->destroy();
}

template<
	typename T,
	typename A
>
void
mizuiro::image::detail::raw_container<
	T,
	A
>::resize(
	size_type const _size
)
{
	this->destroy();

	this->allocate(
		_size
	);
}

template<
	typename T,
	typename A
>
typename
mizuiro::image::detail::raw_container<
	T,
	A
>::pointer
mizuiro::image::detail::raw_container<
	T,
	A
>::data()
{
	return
		data_;
}

template<
	typename T,
	typename A
>
typename
mizuiro::image::detail::raw_container<
	T,
	A
>::const_pointer
mizuiro::image::detail::raw_container<
	T,
	A
>::data() const
{
	return
		data_;
}

template<
	typename T,
	typename A
>
typename
mizuiro::image::detail::raw_container<
	T,
	A
>::pointer
mizuiro::image::detail::raw_container<
	T,
	A
>::data_end()
{
	return
		data_end_;
}

template<
	typename T,
	typename A
>
typename
mizuiro::image::detail::raw_container<
	T,
	A
>::const_pointer
mizuiro::image::detail::raw_container<
	T,
	A
>::data_end() const
{
	return
		data_end_;
}

template<
	typename T,
	typename A
>
typename
mizuiro::image::detail::raw_container<
	T,
	A
>::size_type
mizuiro::image::detail::raw_container<
	T,
	A
>::size() const
{
	return
		static_cast<
			size_type
		>(
			data_end_ - data_
		);
}

template<
	typename T,
	typename A
>
void
mizuiro::image::detail::raw_container<
	T,
	A
>::allocate(
	size_type const _size
)
{
	data_ =
		allocator.allocate(
			_size,
			nullptr
		);

	data_end_ = data_ + _size;
}

template<
	typename T,
	typename A
>
void
mizuiro::image::detail::raw_container<
	T,
	A
>::copy(
	raw_container const &_other
)
{
	this->allocate(
		_other.size()
	);

	if(
		_other.data()
	)
		std::uninitialized_copy(
			_other.data(),
			_other.data_end(),
			this->data()
		);
}

template<
	typename T,
	typename A
>
void
mizuiro::image::detail::raw_container<
	T,
	A
>::destroy()
{
	if(
		data_
	)
		allocator.deallocate(
			data_,
			this->size()
		);
}

template<
	typename T,
	typename A
>
void
mizuiro::image::detail::raw_container<
	T,
	A
>::after_move()
{
	data_ =
		nullptr;

	data_end_ =
		nullptr;
}

#endif
