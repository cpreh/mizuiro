#ifndef MIZUIR_IMAGE_PITCH_ITERATOR_IMPL_HPP_INCLUDED
#define MIZUIR_IMAGE_PITCH_ITERATOR_IMPL_HPP_INCLUDED

#include <mizuiro/image/pitch_iterator_decl.hpp>
#include <numeric>
#include <functional>

#include <iostream>

template<
	typename Format,
	typename Constness
>
mizuiro::image::pitch_iterator<Format, Constness>::pitch_iterator(
	dim_type const &dim_,
	pointer const data_,
	pointer const begin_,
	pitch_type const &pitch_
)
:
	dim_(dim_),
	data_(data_),
	begin_(begin_),
	pitch_(pitch_)
{}

template<
	typename Format,
	typename Constness
>
typename mizuiro::image::pitch_iterator<Format, Constness>::pointer
mizuiro::image::pitch_iterator<Format, Constness>::data() const
{
	return data_;
}

template<
	typename Format,
	typename Constness
>
void
mizuiro::image::pitch_iterator<Format, Constness>::advance(
	difference_type const diff
)
{
	std::cout << "advance: " << diff << '\n';

	size_type const stride(
		Format::color_format::element_count
	);

	size_type add = diff * stride;

	for(
		size_type i = 0;
		i < pitch_type::static_size;
		++i
	)
	{
		size_type temp = (
			(diff * stride +
				(data_ - begin_)
				% (
					std::accumulate(
						dim_.begin(),
						dim_.begin() + i + 1,
						1,
						std::multiplies<
							size_type
						>()
					)
					* stride
					+ std::accumulate(
						pitch_.begin(),
						pitch_.begin() + i + 1,
						0,
						std::plus<
							size_type
						>()
					)
				)
			) / (std::accumulate(dim_.begin(),dim_.begin()+i+1,1,std::multiplies<size_type>()) * stride)
		) * pitch_[i];

		std::cout << "add (" << i << "): " << temp << '\n';

		add += temp;
	}

	data_ += add;
}

template<
	typename Format,
	typename Constness
>
void
mizuiro::image::pitch_iterator<Format, Constness>::increment()
{
	advance(1);
}

template<
	typename Format,
	typename Constness
>
void
mizuiro::image::pitch_iterator<Format, Constness>::decrement()
{
	advance(-1);
}

template<
	typename Format,
	typename Constness
>
typename mizuiro::image::pitch_iterator<Format, Constness>::difference_type
mizuiro::image::pitch_iterator<Format, Constness>::distance_to(
	pitch_iterator const &other
) const
{
	return other.data_ - data_;
}

template<
	typename Format,
	typename Constness
>
typename mizuiro::image::pitch_iterator<Format, Constness>::reference
mizuiro::image::pitch_iterator<Format, Constness>::dereference() const
{
	return reference(
		data_
	);
}

template<
	typename Format,
	typename Constness
>
bool
mizuiro::image::pitch_iterator<Format, Constness>::equal(
	pitch_iterator const &other
) const
{
	return data_ == other.data_;
}

#endif
