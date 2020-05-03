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
	using
	access
	=
	Access;

	using
	format
	=
	Format;

	using
	constness
	=
	Constness;

	using
	format_store_type
	=
	mizuiro::image::format::store<
		format
	>;

	using
	pointer
	=
	mizuiro::image::types::pointer<
		access,
		format,
		constness
	>;

	using
	reference
	=
	mizuiro::image::types::reference<
		access,
		format,
		constness
	>;

	using
	linear_view
	=
	mizuiro::image::linear_view<
		access,
		format,
		constness
	>;

	using
	pitch_view
	=
	mizuiro::image::pitch_view<
		access,
		format,
		constness
	>;

	using
	view_variant
	=
	fcppt::variant::object<
		linear_view,
		pitch_view
	>;

	using
	iterator
	=
	mizuiro::image::iterator<
		access,
		format,
		constness
	>;

	using
	dim
	=
	typename
	format::dim;

	using
	bound_type
	=
	mizuiro::image::bound<
		dim::static_size,
		typename dim::value_type
	>;

	using
	pitch_type
	=
	mizuiro::image::pitch_type<
		typename
		format::dim
	>;

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

	[[nodiscard]]
	dim
	size() const;

	[[nodiscard]]
	pitch_type
	pitch() const;

	[[nodiscard]]
	iterator
	begin() const;

	[[nodiscard]]
	iterator
	end() const;

	[[nodiscard]]
	reference
	operator[](
		dim const &
	) const;

	[[nodiscard]]
	pointer
	data() const;

	[[nodiscard]]
	format_store_type
	format_store() const;

	[[nodiscard]]
	view_variant const &
	impl() const;
private:
	view_variant impl_;
};

}
}

#endif
