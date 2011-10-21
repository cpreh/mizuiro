//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_PITCH_ITERATOR_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_PITCH_ITERATOR_DECL_HPP_INCLUDED

#include <mizuiro/image/format_argument.hpp>
#include <mizuiro/image/format_base_decl.hpp>
#include <mizuiro/image/pitch_iterator_fwd.hpp>
#include <mizuiro/image/detail/iterator_base.hpp>
#include <mizuiro/image/detail/pitch_type.hpp>
#include <mizuiro/image/detail/stacked_dim_array.hpp>
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
	>::type,
	private image::format_base<
		Format
	>::type
{
	typedef typename image::format_base<
		Format
	>::type format_base;
public:
	typedef Access access;

	typedef Format format;

	typedef Constness constness;

	typedef typename format_base::format_store_type format_store_type;

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

	typedef typename format::dim dim;

	typedef typename detail::pitch_type<
		dim
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
		dim const &,
		pointer data,
		pitch_type const &,
		format_store_type const & =
			image::format_argument<format>::get()
	);

	dim const &
	size() const;

	difference_type
	offset() const;

	pointer
	data() const;

	pointer
	root_data() const;

	pitch_type const &
	pitch() const;

	format_store_type const
	format_store() const;
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

	dim size_;

	pointer root_data_;

	pitch_type pitch_;

	difference_type
		line_advance_,
		position_,
		offset_;

	typedef typename detail::stacked_dim_array<
		dim,
		difference_type
	>::type stacked_dim_array;

	stacked_dim_array stacked_dim_;
};

}
}

#endif
