//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_STORE_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_STORE_DECL_HPP_INCLUDED

#include <mizuiro/const_tag.hpp>
#include <mizuiro/nonconst_tag.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/image/format_argument.hpp>
#include <mizuiro/image/format_base_decl.hpp>
#include <mizuiro/image/linear_view_fwd.hpp>
#include <mizuiro/image/store_fwd.hpp>
#include <mizuiro/image/detail/raw_container_decl.hpp>
#include <mizuiro/image/types/data_store.hpp>
#include <mizuiro/image/types/normal.hpp>
#include <mizuiro/image/types/pointer.hpp>


namespace mizuiro
{
namespace image
{

MIZUIRO_DETAIL_IGNORE_EFFCPP

template<
	typename Format,
	typename Access
>
class store
:
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

	typedef typename format_base::format_store_type format_store_type;

	typedef typename format::color_format color_format;

	typedef typename image::types::pointer<
		access,
		format,
		mizuiro::nonconst_tag
	>::type pointer;

	typedef typename image::types::pointer<
		access,
		format,
		mizuiro::const_tag
	>::type const_pointer;

	typedef typename format::dim dim;

	typedef image::linear_view<
		access,
		format,
		mizuiro::nonconst_tag
	> view_type;

	typedef image::linear_view<
		access,
		format,
		mizuiro::const_tag
	> const_view_type;

	explicit store(
		format_store_type const & =
			image::format_argument<format>::get()
	);

	explicit store(
		dim const &,
		format_store_type const & =
			image::format_argument<format>::get()
	);

	pointer
	data();

	const_pointer
	data() const;

	view_type const
	view();

	const_view_type const
	view() const;

	dim const &
	size() const;
private:
	dim size_;

	typedef typename mizuiro::image::types::data_store<
		access,
		typename format::color_format // TODO!
	>::type container;

	container data_;
};

MIZUIRO_DETAIL_POP_WARNING

}
}

#endif
