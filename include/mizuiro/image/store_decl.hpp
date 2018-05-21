//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_STORE_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_STORE_DECL_HPP_INCLUDED

#include <mizuiro/const_tag.hpp>
#include <mizuiro/empty_fwd.hpp>
#include <mizuiro/no_init_fwd.hpp>
#include <mizuiro/nonconst_tag.hpp>
#include <mizuiro/image/dimension_decl.hpp>
#include <mizuiro/image/linear_view_fwd.hpp>
#include <mizuiro/image/store_fwd.hpp>
#include <mizuiro/image/format/argument.hpp>
#include <mizuiro/image/format/base_decl.hpp>
#include <mizuiro/image/types/pointer.hpp>
#include <mizuiro/image/types/store.hpp>
#include <mizuiro/image/types/value_type.hpp>


namespace mizuiro
{
namespace image
{

template<
	typename Format,
	typename Access
>
class store
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
	typename
	format_base::format_store_type
	format_store_type;

	typedef
	mizuiro::image::types::pointer<
		access,
		format,
		mizuiro::nonconst_tag
	>
	pointer;

	typedef
	mizuiro::image::types::pointer<
		access,
		format,
		mizuiro::const_tag
	>
	const_pointer;

	typedef
	typename
	format::dim dim;

	typedef
	mizuiro::image::types::value_type<
		format
	>
	value_type;

	typedef
	mizuiro::image::linear_view<
		access,
		format,
		mizuiro::nonconst_tag
	>
	view_type;

	typedef
	mizuiro::image::linear_view<
		access,
		format,
		mizuiro::const_tag
	>
	const_view_type;

	store(
		dim const &,
		mizuiro::no_init const &,
		format_store_type const & =
			mizuiro::image::format::argument<
				format
			>::get()
	);

	explicit
	store(
		mizuiro::empty const &,
		format_store_type const & =
			mizuiro::image::format::argument<
				format
			>::get()
	);

	store(
		dim const &,
		value_type const &,
		format_store_type const & =
			mizuiro::image::format::argument<
				format
			>::get()
	);

	template<
		typename Function
	>
	store(
		dim const &,
		Function const &,
		format_store_type const & =
			mizuiro::image::format::argument<
				format
			>::get()
	);

	pointer
	data();

	const_pointer
	data() const;

	view_type
	view();

	const_view_type
	view() const;

	dim const &
	size() const;

	format_store_type
	format_store() const;
private:
	dim size_;

	typedef
	mizuiro::image::types::store<
		access,
		format
	>
	container;

	container data_;
};

}
}

#endif
