#ifndef MIZUIRO_IMAGE_VIEW_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_VIEW_DECL_HPP_INCLUDED

#include <mizuiro/image/view_fwd.hpp>
#include <mizuiro/image/iterator_fwd.hpp>
#include <mizuiro/detail/apply_const.hpp>

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
	typedef image::iterator<
		Format,
		Constness
	> iterator;

	typedef Format format;

	typedef typename format::dim_type dim_type;
	typedef typename format::pitch_type pitch_type;

	//typedef typename iterator::reference reference;
	typedef typename mizuiro::detail::apply_const<
		typename format::pointer,
		Constness
	>::type pointer;

	view(
		dim_type const &,
		pointer data,
		pitch_type const &
	);

	dim_type const &
	dim() const;

	iterator const
	begin() const;

	iterator const
	end() const;

	/*
	reference
	operator[](
		dim_type const &
	) const;

	reference
	at(
		dim_type const &
	) const;
	*/

	pointer
	data() const;
private:
	dim_type dim_;
	pointer data_;
	pitch_type pitch_;
};

}
}

#endif
