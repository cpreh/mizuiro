//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_LINEAR_VIEW_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_LINEAR_VIEW_DECL_HPP_INCLUDED

#include <mizuiro/image/bound_fwd.hpp>
#include <mizuiro/image/linear_iterator_fwd.hpp>
#include <mizuiro/image/linear_view_fwd.hpp>
#include <mizuiro/image/pitch_type.hpp>
#include <mizuiro/image/format/argument.hpp>
#include <mizuiro/image/format/base_decl.hpp>
#include <mizuiro/image/types/pointer.hpp>
#include <mizuiro/image/types/reference.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>


namespace mizuiro::image
{

template<
	typename Access,
	typename Format,
	typename Constness
>
class linear_view final
:
	private
		mizuiro::image::format::base<
			Format
		>
{
	using
	format_base
	=
	mizuiro::image::format::base<
		Format
	>;
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
	typename
	format_base::format_store_type;

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
	iterator
	=
	mizuiro::image::linear_iterator<
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
		typename
		dim::value_type
	>;

	using
	pitch_type
	=
	mizuiro::image::pitch_type<
		typename
		format::dim
	>;

	FCPPT_PP_PUSH_WARNING
	FCPPT_PP_DISABLE_VC_WARNING(4686)

	linear_view(
		dim const &,
		pointer data,
		format_store_type const & =
			mizuiro::image::format::argument<
				format
			>::get()
	);

	FCPPT_PP_POP_WARNING

	template<
		typename OtherConstness
	>
	explicit
	linear_view(
		mizuiro::image::linear_view<
			access,
			format,
			OtherConstness
		> const &
	);

	[[nodiscard]]
	dim const &
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
private:
	dim size_;

	pointer data_;
};

}

#endif
