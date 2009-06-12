#ifndef MIZUIRO_IMAGE_STORE_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_STORE_DECL_HPP_INCLUDED

#include <mizuiro/image/store_fwd.hpp>
#include <mizuiro/raw_container.hpp>

namespace mizuiro
{
namespace image
{

template<
	typename Format
>
class store {
public:
	typedef typename Format::value_type value_type;
	typedef typename Format::pointer pointer;
	typedef typename Format::const_pointer const_pointer;
	typedef typename Format::dim_type dim_type;

	typedef image::view<
		Format,
		detail::nonconst_tag
	> view_type;

	typedef image::view<
		Format,
		detail::const_tag
	> const_view_type;
	
	image();

	explicit image(
		dim_type const &
	);
	
	void
	resize(
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
private:
	dim_type dim_;

	typedef raw_container<
		value_type
	> container;

	container data_;
};

}
}

#endif
