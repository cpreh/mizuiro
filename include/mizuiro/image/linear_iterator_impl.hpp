//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_LINEAR_ITERATOR_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_LINEAR_ITERATOR_IMPL_HPP_INCLUDED

#include <mizuiro/image/linear_iterator_decl.hpp>
#include <mizuiro/image/access/color_stride.hpp>

template<
	typename Access,
	typename Format,
	typename Constness
>
mizuiro::image::linear_iterator<Access, Format, Constness>::linear_iterator(
	pointer const _data,
	format_store_type const &_format
)
:
	base(),
	format_base(
		_format
	),
	data_(
		_data
	)
{
}

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
typename mizuiro::image::linear_iterator<Access, Format, Constness>::format_store_type const
mizuiro::image::linear_iterator<Access, Format, Constness>::format_store() const
{
	return this->format_store_base();
}

template<
	typename Access,
	typename Format,
	typename Constness
>
void
mizuiro::image::linear_iterator<Access, Format, Constness>::advance(
	difference_type	const _diff
)
{
	data_ +=
		_diff
		*
		static_cast<
			difference_type
		>(
			image::access::color_stride<
				Access,
				Format
			>::execute(
				Access(),
				this->format_store_base()
			)
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
	this->advance(
		1
	);
}

template<
	typename Access,
	typename Format,
	typename Constness
>
void
mizuiro::image::linear_iterator<Access, Format, Constness>::decrement()
{
	this->advance(
		-1
	);
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
	return
		(
			_other.data_ - data_
		)
		/
		static_cast<
			difference_type
		>(
			image::access::color_stride<
				Access,
				Format
			>::execute(
				Access(),
				this->format_store_base()
			)
		);
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
			this->data(),
			this->format_store_base().color_format()
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
