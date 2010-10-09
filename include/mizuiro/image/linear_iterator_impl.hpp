//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_LINEAR_ITERATOR_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_LINEAR_ITERATOR_IMPL_HPP_INCLUDED

#include <mizuiro/image/linear_iterator_decl.hpp>
#include <mizuiro/image/underlying_data_pointer.hpp>
#include <mizuiro/access/color_pointer.hpp>

template<
	typename Access,
	typename Format,
	typename Constness
>
mizuiro::image::linear_iterator<Access, Format, Constness>::linear_iterator(
	pointer const _data
)
:
	data_(_data)
{}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename mizuiro::image::linear_iterator<Access, Format, Constness>::pointer
mizuiro::image::linear_iterator<Access, Format, Constness>::data() const
{
	return data_;
}

template<
	typename Access,
	typename Format,
	typename Constness
>
void
mizuiro::image::linear_iterator<Access, Format, Constness>::advance(
	difference_type	const diff
)
{
	data_ +=
		diff
		*
		static_cast<
			difference_type
		>(
			Format::color_format::element_count
		);
}
	
template<
	typename Access,
	typename Format,
	typename Constness
>
void
mizuiro::image::linear_iterator<Access, Format, Constness>::increment()
{
	advance(1);
}

template<
	typename Access,
	typename Format,
	typename Constness
>
void
mizuiro::image::linear_iterator<Access, Format, Constness>::decrement()
{
	advance(-1);
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename mizuiro::image::linear_iterator<Access, Format, Constness>::difference_type
mizuiro::image::linear_iterator<Access, Format, Constness>::distance_to(
	linear_iterator const &_other
) const
{
	return _other.data_ - data_;
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename mizuiro::image::linear_iterator<Access, Format, Constness>::reference
mizuiro::image::linear_iterator<Access, Format, Constness>::dereference() const
{
	return
		reference(
			underlying_data_pointer(
				*this
			)
		);
}

template<
	typename Access,
	typename Format,
	typename Constness
>
bool
mizuiro::image::linear_iterator<Access, Format, Constness>::equal(
	linear_iterator const &_other
) const
{
	return data_ == _other.data_;
}

#endif
