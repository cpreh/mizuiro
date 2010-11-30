//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_RANGE_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_RANGE_IMPL_HPP_INCLUDED

#include <mizuiro/image/range_decl.hpp>

template<
	typename Iterator
>
mizuiro::image::range<Iterator>::range(
	iterator const _begin,
	iterator const _end
)
:
	begin_(_begin),
	end_(_end)
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
