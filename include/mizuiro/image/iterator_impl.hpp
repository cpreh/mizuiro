#include <mizuiro/image/iterator_decl.hpp>
#include <algorithm>
#include <functional>

template<
	typename Format,
	typename Constness
>
void
mizuiro::image::iterator<Format, Constness>::advance(
	difference_type const diff
)
{
	for(
		size_type i = 0;
		i < pitch_type::dim_wrapper::value;
		++i
	)
		data_ += (
			(diff +
				(data_ - begin)
				% std::accumulate(
					dim.begin(),
					dim.begin() + i + 1,
					1,
					std::multiplies<
						size_type
					>()
				)
			) / dim[i]
		) * pitch[i];

	data_ += diff;
}

template<
	typename Format,
	typename Constness
>
void
mizuiro::image::iterator<Format, Constness>::increment()
{
	advance(1);
}

template<
	typename Format,
	typename Constness
>
void
mizuiro::image::iterator<Format, Constness>::decrement()
{
	advance(-1);
}

template<
	typename Format,
	typename Constness
>
typename mizuiro::image::iterator<Format, Constness>::difference_type
mizuiro::image::iterator<Format, Constness>::distance_to(
	iterator const &
) const
{
	return other.data_ - data_;
}

template<
	typename Format,
	typename Constness
>
typename mizuiro::image::iterator<Format, Constness>::reference
mizuiro::image::iterator<Format, Constness>::dereference() const
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
mizuiro::image::iterator<Format, Constness>::equal(
	iterator const &other
) const
{
	return data_ == other.data_;
}
