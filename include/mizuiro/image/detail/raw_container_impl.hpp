#ifndef MIZUIRO_IMAGE_DETAIL_RAW_CONTAINER_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_RAW_CONTAINER_IMPL_HPP_INCLUDED

#include <mizuiro/image/detail/raw_container_decl.hpp>
#include <memory>

template<
	typename T,
	typename A
>
mizuiro::image::detail::raw_container<T, A>::raw_container()
:
	allocator(),
	data_(0),
	data_end_(0)
{}

template<
	typename T,
	typename A
>
mizuiro::image::detail::raw_container<T, A>::raw_container(
	size_type const sz
)
:
	allocator(),
	data_(),
	data_end_()
{
	allocate(sz);
}

template<
	typename T,
	typename A
>
mizuiro::image::detail::raw_container<T, A>::raw_container(
	raw_container const &other
)
{
	copy(
		other
	);
}

template<
	typename T,
	typename A
>
mizuiro::image::detail::raw_container<T, A> &
mizuiro::image::detail::raw_container<T, A>::operator=(
	raw_container const &other
)
{
	if(
		this == &other
	)
		return *this;
	
	destroy();

	copy(
		other
	);

	return *this;
}

template<
	typename T,
	typename A
>
mizuiro::image::detail::raw_container<T, A>::~raw_container()
{
	destroy();
}

template<
	typename T,
	typename A
>
void
mizuiro::image::detail::raw_container<T, A>::resize(
	size_type const nsz
)
{
	destroy();

	allocate(
		nsz
	);
}

template<
	typename T,
	typename A
>
typename mizuiro::image::detail::raw_container<T, A>::pointer
mizuiro::image::detail::raw_container<T, A>::data()
{
	return data_;
}

template<
	typename T,
	typename A
>
typename mizuiro::image::detail::raw_container<T, A>::const_pointer
mizuiro::image::detail::raw_container<T, A>::data() const
{
	return data_;
}

template<
	typename T,
	typename A
>
typename mizuiro::image::detail::raw_container<T, A>::pointer
mizuiro::image::detail::raw_container<T, A>::data_end()
{
	return data_end_;
}

template<
	typename T,
	typename A
>
typename mizuiro::image::detail::raw_container<T, A>::const_pointer
mizuiro::image::detail::raw_container<T, A>::data_end() const
{
	return data_end_;
}

template<
	typename T,
	typename A
>
typename mizuiro::image::detail::raw_container<T, A>::size_type
mizuiro::image::detail::raw_container<T, A>::size() const
{
	return data_end_ - data_;
}

template<
	typename T,
	typename A
>
void
mizuiro::image::detail::raw_container<T, A>::allocate(
	size_type const sz
)
{
	data_ = allocator.allocate(sz);
	data_end_ = data_ + sz;
}

template<
	typename T,
	typename A
>
void
mizuiro::image::detail::raw_container<T, A>::copy(
	raw_container const &other
)
{
	allocate(
		other.size()
	);
	
	std::uninitialized_copy(
		other.data(),
		other.data_end(),
		data()
	);
}

template<
	typename T,
	typename A
>
void
mizuiro::image::detail::raw_container<T, A>::destroy()
{
	if(data_)
		allocator.deallocate(
			data_,
			size()
		);
}

#endif
