//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_VIEW_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_VIEW_DECL_HPP_INCLUDED

#include <mizuiro/image/view_fwd.hpp>
#include <mizuiro/image/iterator_fwd.hpp>
#include <mizuiro/image/range_fwd.hpp>
#include <mizuiro/image/pitch_iterator_fwd.hpp>
#include <mizuiro/image/linear_iterator_fwd.hpp>
#include <mizuiro/image/bound_fwd.hpp>
#include <mizuiro/image/types/reference.hpp>
#include <mizuiro/image/types/pointer.hpp>
#include <mizuiro/image/types/normal.hpp>
#include <mizuiro/detail/make_variant.hpp>
#include <boost/mpl/vector/vector10.hpp>

namespace mizuiro
{
namespace image
{

template<
	typename Access,
	typename Format,
	typename Constness
>
class view
{
public:
	typedef Access access;

	typedef Format format;

	typedef Constness constness;

	typedef image::iterator<
		access,
		format,
		constness
	> iterator;

	typedef image::pitch_iterator<
		access,
		format,
		constness
	> pitch_iterator;

	typedef image::linear_iterator<
		access,
		format,
		constness
	> linear_iterator;

	typedef image::range<
		pitch_iterator
	> pitch_range;

	typedef image::range<
		linear_iterator
	> linear_range;
	
	typedef typename mizuiro::detail::make_variant<
		boost::mpl::vector2<
			linear_range,
			pitch_range
		>
	>::type range_type;

	typedef typename format::color_format color_format;

	typedef typename format::dim_type dim_type;

	typedef bound<
		dim_type::static_size,
		typename dim_type::value_type
	> bound_type;

	typedef typename format::pitch_type pitch_type;
	
	typedef typename image::types::reference<
		access,
		format,
		Constness
	>::type reference;

	typedef typename image::types::pointer<
		access,
		format,
		Constness
	>::type pointer;

	view(
		dim_type const &,
		pointer data
	);

	view(
		dim_type const &,
		pointer data,
		pitch_type const &
	);

	view(
		view const &
	);

	template<
		typename OtherConstness
	>
	explicit view(
		view<
			access,
			format,
			OtherConstness
		> const &
	);

	dim_type const &
	dim() const;

	iterator const
	begin() const;

	iterator const
	end() const;

	range_type const
	range() const;

	reference
	operator[](
		dim_type const &
	) const;

	reference
	at(
		dim_type const &
	) const;

	pointer
	data() const;

	pitch_type const &
	pitch() const;
private:
	bool
	is_linear() const;

	linear_iterator const
	linear_begin() const;

	linear_iterator const
	linear_end() const;

	pitch_iterator const
	pitch_begin() const;

	pitch_iterator const
	pitch_end() const;

	dim_type dim_;
	pointer data_;
	pitch_type pitch_;
};

}
}

#endif
