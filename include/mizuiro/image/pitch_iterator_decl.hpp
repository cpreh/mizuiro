//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_PITCH_ITERATOR_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_PITCH_ITERATOR_DECL_HPP_INCLUDED

#include <mizuiro/image/pitch_iterator_fwd.hpp>
#include <mizuiro/image/detail/iterator_base.hpp>
#include <mizuiro/image/detail/pitch_type.hpp>
#include <mizuiro/image/detail/stacked_dim_type.hpp>
#include <mizuiro/image/types/pointer.hpp>

namespace mizuiro
{
namespace image
{

template<
	typename Access,
	typename Format,
	typename Constness
>
class pitch_iterator 
:
	public detail::iterator_base<
		pitch_iterator<
			Access,
			Format,
			Constness
		>,
		Access,
		Format,
		Constness
	>::type
{
public:
	typedef Access access;

	typedef Format format;

	typedef Constness constness; 

	typedef typename format::color_format color_format;

	typedef typename detail::iterator_base<
		pitch_iterator<
			access,
			format,
			constness
		>,
		access,
		format,
		constness
	>::type base;

	typedef typename format::dim_type dim_type;

	typedef typename detail::pitch_type<
		dim_type
	>::type pitch_type;

	typedef typename base::value_type value_type;

	typedef typename base::reference reference;

	typedef typename image::types::pointer<
		access,
		format,
		Constness
	>::type pointer;

	typedef typename base::difference_type difference_type;

	typedef typename base::iterator_category iterator_category;

	pitch_iterator(
		dim_type const &,
		pointer data,
		pitch_type const &
	);

	dim_type const &
	dim() const;

	difference_type
	offset() const;

	pointer
	data() const;

	pointer
	root_data() const;

	pitch_type const &
	pitch() const;
private:
	friend class boost::iterator_core_access;

	void
	advance(
		difference_type
	);
	
	void
	increment();

	void
	decrement();

	difference_type
	distance_to(
		pitch_iterator const &
	) const;

	reference
	dereference() const;

	bool
	equal(
		pitch_iterator const &
	) const;

	dim_type dim_;

	pointer root_data_;

	pitch_type pitch_;

	difference_type
		line_advance_,
		position_,
		offset_;

	typedef typename detail::stacked_dim_type<
		dim_type,
		difference_type
	>::type stacked_dim_array;

	stacked_dim_array stacked_dim_;
};

}
}

#endif
