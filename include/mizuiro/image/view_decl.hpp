#ifndef MIZUIRO_IMAGE_VIEW_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_VIEW_DECL_HPP_INCLUDED

#include <mizuiro/image/view_fwd.hpp>

namespace mizuiro
{
namespace image
{

template<
	typename Format,
	typename Constness
>
class view {
public:
	typedef Format format;

	typedef typename Format::dim_type dim_type;

	typedef typename detail::const_cond<
		typename Format::pointer,
		Constness
	>::type pointer;

	typedef image::iterator<
		format,
		Constness
	> iterator;

	typedef typename iterator::reference reference;

	view(
		dim_type const &,
		pointer begin,
		pointer data
	);

	dim_type const
	dim();

	iterator
	begin() const;

	iterator
	end() const;

	reference
	operator[](
		dim_type const &
	) const;

	reference
	at(
		dim_type const &
	) const;
private:
	dim_type dim_;
	pointer data_;
};

}
}

#endif
