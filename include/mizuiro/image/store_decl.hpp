#ifndef MIZUIRO_IMAGE_STORE_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_STORE_DECL_HPP_INCLUDED

#include <mizuiro/image/store_fwd.hpp>
#include <mizuiro/image/view_fwd.hpp>
#include <mizuiro/image/detail/raw_container_decl.hpp>
#include <mizuiro/const_tag.hpp>
#include <mizuiro/nonconst_tag.hpp>

namespace mizuiro
{
namespace image
{

template<
	typename Format
>
class store {
public:
	typedef typename Format::channel_type channel_type;
	typedef typename Format::pointer pointer;
	typedef typename Format::const_pointer const_pointer;
	typedef typename Format::dim_type dim_type;

	typedef image::view<
		Format,	
		mizuiro::nonconst_tag
	> view_type;

	typedef image::view<
		Format,
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
