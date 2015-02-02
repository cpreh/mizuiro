//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_DETAIL_PITCH_ITERATOR_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_PITCH_ITERATOR_DECL_HPP_INCLUDED

#include <mizuiro/difference_type.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/image/pitch_type.hpp>
#include <mizuiro/image/detail/pitch_iterator_fwd.hpp>
#include <mizuiro/image/detail/stacked_dim_array.hpp>
#include <mizuiro/image/format/base_decl.hpp>
#include <mizuiro/image/types/pointer.hpp>
#include <mizuiro/image/types/reference.hpp>


namespace mizuiro
{
namespace image
{
namespace detail
{

MIZUIRO_DETAIL_IGNORE_EFFCPP

template<
	typename Access,
	typename Format,
	typename Constness
>
class pitch_iterator final
:
	private
		mizuiro::image::format::base<
			Format
		>
{
	typedef
	mizuiro::image::format::base<
		Format
	>
	format_base;
public:
	typedef
	Access
	access;

	typedef
	Format
	format;

	typedef
	Constness
	constness;

	typedef
	typename
	format_base::format_store_type
	format_store_type;

	typedef
	typename
	format::dim dim;

	typedef
	mizuiro::image::pitch_type<
		dim
	>
	pitch_type;

	typedef
	mizuiro::image::types::reference<
		access,
		format,
		constness
	>
	reference;

	typedef
	mizuiro::image::types::pointer<
		access,
		format,
		constness
	>
	pointer;

	typedef
	mizuiro::difference_type
	difference_type;

	pitch_iterator(
		dim const &,
		pointer data,
		pitch_type const &,
		format_store_type const &
	);

	pitch_iterator(
		pitch_iterator const &
	) noexcept;

	dim const &
	size() const;

	difference_type
	offset() const;

	pointer
	data() const;

	pitch_iterator &
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
private:
	dim size_;

	pointer root_data_;

	pitch_type pitch_;

	difference_type
		line_advance_,
		position_,
		offset_;

	typedef
	mizuiro::image::detail::stacked_dim_array<
		dim,
		difference_type
	>
	stacked_dim_array;

	stacked_dim_array stacked_dim_;
};

MIZUIRO_DETAIL_POP_WARNING

}
}
}

#endif
