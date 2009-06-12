#include <mizuiro/image/iterator_decl.hpp>

void advance(
	difference_type const diff
)
{
	data_ += diff;
}
	void increment()
	{
		advance(1);
	}

	void decrement()
	{
		advance(-1);
	}

	difference_type
	distance_to(
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
		data
	);
}

bool
equal(
	iterator const &other
) const
{
	return data_ == other.data_;
}
