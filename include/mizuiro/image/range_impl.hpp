#ifndef MIZUIRO_IMAGE_RANGE_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_RANGE_IMPL_HPP_INCLUDED

#include <mizuiro/image/range_decl.hpp>

template<
	typename Iterator
>
mizuiro::image::range<Iterator>::range(
	iterator const begin_,
	iterator const end_
)
:
	begin_(begin_),
	end_(end_)
{}

template<
	typename Iterator
>
typename mizuiro::image::range<Iterator>::iterator const
mizuiro::image::range<Iterator>::begin() const
{
	return begin_;
}

template<
	typename Iterator
>
typename mizuiro::image::range<Iterator>::iterator const
mizuiro::image::range<Iterator>::end() const
{
	return end_;
}

#endif
