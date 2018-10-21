//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_INDEXED_REF_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_INDEXED_REF_IMPL_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <mizuiro/image/indexed_ref_decl.hpp>


template<
	mizuiro::size_type Size,
	typename Reference
>
mizuiro::image::indexed_ref<
	Size,
	Reference
>::indexed_ref(
	dim const &_index,
	Reference _reference
)
:
	index_(
		_index
	),
	reference_(
		_reference
	)
{
}

template<
	mizuiro::size_type Size,
	typename Reference
>
Reference
mizuiro::image::indexed_ref<
	Size,
	Reference
>::get() const
{
	return
		reference_.get();
}

template<
	mizuiro::size_type Size,
	typename Reference
>
typename
mizuiro::image::indexed_ref<
	Size,
	Reference
>::dim const &
mizuiro::image::indexed_ref<
	Size,
	Reference
>::index() const
{
	return
		index_;
}

#endif
