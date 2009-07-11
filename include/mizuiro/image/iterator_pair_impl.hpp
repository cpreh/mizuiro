#ifndef MIZUIRO_IMAGE_ITERATOR_PAIR_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_ITERATOR_PAIR_IMPL_HPP_INCLUDED

#include <mizuiro/image/iterator_pair_decl.hpp>

template<
	typename Iterator
>
mizuiro::image::iterator_pair<Iterator>::iterator_pair(
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
typename mizuiro::image::iterator_pair<Iterator>::iterator const
mizuiro::image::iterator_pair<Iterator>::begin() const
{
	return begin_;
}

template<
	typename Iterator
>
typename mizuiro::image::iterator_pair<Iterator>::iterator const
mizuiro::image::iterator_pair<Iterator>::end() const
{
	return end_;
}

#endif
