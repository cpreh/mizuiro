#ifndef MIZUIRO_IMAGE_VIEW_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_VIEW_DECL_HPP_INCLUDED

#include <mizuiro/image/view_fwd.hpp>

namespace mizuiro
{
namespace image
{

template<
	typename Iterator
>
class view {
public:
	typedef Iterator iterator;
	typedef typename iterator::format format;

	typedef typename format::dim_type dim_type;
	typedef typename format::pitch_type pitch_type;

	typedef typename iterator::reference reference;
	typedef typename iterator::pointer pointer;

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
	pitch_type pitch_;
};

}
}

#endif
