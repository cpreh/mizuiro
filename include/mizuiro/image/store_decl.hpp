#ifndef MIZUIRO_IMAGE_STORE_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_STORE_DECL_HPP_INCLUDED

#include <mizuiro/image/store_fwd.hpp>
#include <mizuiro/image/view_fwd.hpp>
#include <mizuiro/image/detail/raw_container_decl.hpp>
#include <mizuiro/color/types/pointer.hpp>
#include <mizuiro/access/normal.hpp>
#include <mizuiro/const_tag.hpp>
#include <mizuiro/nonconst_tag.hpp>

namespace mizuiro
{
namespace image
{

template<
	typename Format
>
class store
{
public:
	typedef ::mizuiro::access::normal access;

	typedef Format format;

	typedef typename format::color_format color_format;

	typedef typename color_format::channel_type channel_type; // TODO!

	typedef typename color::types::pointer<
		access,
		color_format,
		mizuiro::nonconst_tag
	>::type pointer;

	typedef typename color::types::pointer<
		access,
		color_format,
		mizuiro::const_tag
	>::type const_pointer;

	typedef typename format::dim_type dim_type;

	typedef image::view<
		access,
		format,	
		mizuiro::nonconst_tag
	> view_type;

	typedef image::view<
		access,
		format,
		mizuiro::const_tag
	> const_view_type;
	
	store();

	explicit store(
		dim_type const &
	);
	
	pointer
	data();

	const_pointer
	data() const;

	view_type const
	view();

	const_view_type const
	view() const;

	dim_type const &
	dim() const;
private:
	dim_type dim_;

	typedef detail::raw_container<
		channel_type
	> container;

	container data_;
};

}
}

#endif
