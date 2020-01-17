//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_VIEW_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_VIEW_DECL_HPP_INCLUDED

#include <mizuiro/image/iterator_fwd.hpp>
#include <mizuiro/image/linear_view_decl.hpp>
#include <mizuiro/image/pitch_type.hpp>
#include <mizuiro/image/pitch_view_decl.hpp>
#include <mizuiro/image/view_fwd.hpp>
#include <mizuiro/image/format/store_fwd.hpp>
#include <mizuiro/image/types/pointer.hpp>
#include <mizuiro/image/types/reference.hpp>
#include <fcppt/variant/object_impl.hpp>


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
	mizuiro::image::format::store<
		format
	>
	format_store_type;

	typedef
	mizuiro::image::types::pointer<
		access,
		format,
		constness
	>
	pointer;

	typedef
	mizuiro::image::types::reference<
		access,
		format,
		constness
	>
	reference;

	typedef
	mizuiro::image::linear_view<
		access,
		format,
		constness
	>
	linear_view;

	typedef
	mizuiro::image::pitch_view<
		access,
		format,
		constness
	>
	pitch_view;

	typedef
	fcppt::variant::object<
		linear_view,
		pitch_view
	>
	view_variant;

	typedef
	mizuiro::image::iterator<
		access,
		format,
		constness
	>
	iterator;

	typedef
	typename
	format::dim dim;

	typedef
	mizuiro::image::bound<
		dim::static_size,
		typename dim::value_type
	>
	bound_type;

	typedef
	mizuiro::image::pitch_type<
		typename
		format::dim
	>
	pitch_type;

	explicit
	view(
		linear_view const &
	);

	explicit
	view(
		pitch_view const &
	);

	view(
		dim const &,
		pointer data,
		pitch_type const &,
		format_store_type const & =
			mizuiro::image::format::argument<
				format
			>::get()
	);

	view(
		dim const &,
		pointer data,
		format_store_type const & =
			mizuiro::image::format::argument<
				format
			>::get()
	);

	template<
		typename OtherConstness
	>
	explicit
	view(
		view<
			access,
			format,
			OtherConstness
		> const &
	);

	dim
	size() const;

	pitch_type
	pitch() const;

	iterator
	begin() const;

	iterator
	end() const;

	reference
	operator[](
		dim const &
	) const;

	pointer
	data() const;

	format_store_type
	format_store() const;

	view_variant const &
	impl() const;
private:
	view_variant impl_;
};

}
}

#endif
