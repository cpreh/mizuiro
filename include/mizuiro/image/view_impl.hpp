#ifndef MIZUIRO_IMAGE_VIEW_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_VIEW_IMPL_HPP_INCLUDED

#include <mizuiro/image/view_decl.hpp>
#include <mizuiro/image/iterator_impl.hpp>
#include <mizuiro/image/pitch_iterator_impl.hpp>
#include <mizuiro/image/linear_iterator_impl.hpp>
#include <mizuiro/image/range_impl.hpp>
#include <mizuiro/image/move_iterator.hpp>
#include <stdexcept>

template<
	typename Access,
	typename Format,
	typename Constness
>
mizuiro::image::view<Access, Format, Constness>::view(
	dim_type const &dim_,
	pointer const data_
)
:
	dim_(dim_),
	data_(data_),
	pitch_(pitch_type::null())
{}

template<
	typename Access,
	typename Format,
	typename Constness
>
mizuiro::image::view<Access, Format, Constness>::view(
	dim_type const &dim_,
	pointer const data_,
	pitch_type const &pitch_
)
:
	dim_(dim_),
	data_(data_),
	pitch_(pitch_)
{}

template<
	typename Access,
	typename Format,
	typename Constness
>
mizuiro::image::view<Access, Format, Constness>::view(
	view const &v
)
:
	dim_(v.dim_),
	data_(v.data_),
	pitch_(v.pitch_)
{}

template<
	typename Access,
	typename Format,
	typename Constness
>
template<
	typename OtherConstness
>
mizuiro::image::view<Access, Format, Constness>::view(
	view<
		Format,
		OtherConstness
	> const &other
)
:
	dim_(other.dim()),
	data_(other.data()),
	pitch_(other.pitch())
{}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename mizuiro::image::view<Access, Format, Constness>::dim_type const &
mizuiro::image::view<Access, Format, Constness>::dim() const
{
	return dim_;
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename mizuiro::image::view<Access, Format, Constness>::iterator const
mizuiro::image::view<Access, Format, Constness>::begin() const
{
	return is_linear()
		? iterator(
			linear_begin()
		)
		: iterator(
			pitch_begin()	
		);
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename mizuiro::image::view<Access, Format, Constness>::iterator const
mizuiro::image::view<Access, Format, Constness>::end() const
{
	return begin() + dim().content();
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename mizuiro::image::view<Access, Format, Constness>::range_type const
mizuiro::image::view<Access, Format, Constness>::range() const
{
	return is_linear()
		? range_type(
			linear_range(
				linear_begin(),
				linear_end()
			)
		)
		: range_type(
			pitch_range(
				pitch_begin(),
				pitch_end()
			)
		);
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename mizuiro::image::view<Access, Format, Constness>::reference
mizuiro::image::view<Access, Format, Constness>::operator[](
	dim_type const &index
) const
{
	return *move_iterator(
		*this,
		index
	);
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename mizuiro::image::view<Access, Format, Constness>::reference
mizuiro::image::view<Access, Format, Constness>::at(
	dim_type const &index
) const
{
	for(
		size_type i = 0;
		i < dim_type::static_size;
		++i
	)
		// TODO: replace this with our own exception and add a better error message!
		if(index[i] >= dim()[i])
			throw std::range_error("view::at out of range");
	
	return (*this)[index];
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename mizuiro::image::view<Access, Format, Constness>::pointer
mizuiro::image::view<Access, Format, Constness>::data() const
{
	return data_;
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename mizuiro::image::view<Access, Format, Constness>::pitch_type const &
mizuiro::image::view<Access, Format, Constness>::pitch() const
{
	return pitch_;
}

template<
	typename Access,
	typename Format,
	typename Constness
>
bool
mizuiro::image::view<Access, Format, Constness>::is_linear() const
{
	return pitch_ == pitch_type::null();
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename mizuiro::image::view<Access, Format, Constness>::linear_iterator const
mizuiro::image::view<Access, Format, Constness>::linear_begin() const
{
	return linear_iterator(
		data_
	);
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename mizuiro::image::view<Access, Format, Constness>::linear_iterator const
mizuiro::image::view<Access, Format, Constness>::linear_end() const
{
	return linear_begin() + dim().content();
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename mizuiro::image::view<Access, Format, Constness>::pitch_iterator const
mizuiro::image::view<Access, Format, Constness>::pitch_begin() const
{
	return pitch_iterator(
		dim(),
		data_,
		pitch_ 
	);
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename mizuiro::image::view<Access, Format, Constness>::pitch_iterator const
mizuiro::image::view<Access, Format, Constness>::pitch_end() const
{
	// TODO: Fix this! pitch_iterator doesn't like to be empty and incremented!
	return dim().content()
		? pitch_begin() + dim().content()
		: pitch_begin();
}

#endif
