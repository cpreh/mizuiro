#ifndef MIZUIRO_IMAGE_ITERATOR_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_ITERATOR_DECL_HPP_INCLUDED

#include <mizuiro/image/iterator_fwd.hpp>
#include <mizuiro/image/detail/iterator_base.hpp>

namespace mizuiro
{
namespace image
{

template<
	typename Format,
	typename Constness
>
class iterator 
:
	public detail::iterator_base<
		iterator<
			Format,
			Constness
		>,
		Format,
		Constness
	>::type
{
public:
	typedef Format format;
	typedef Constness constness; 

	typedef typename detail::iterator_base<
		iterator<
			format,
			constness
		>,
		format,
		constness
	>::type base;

	typedef typename format::dim_type dim_type;

	typedef typename detail::pitch_type<
		dim_type
	> pitch_type;

	typedef typename base::value_type value_type;
	typedef typename base::reference reference;
	typedef typename format::pointer pointer;
	typedef typename base::difference_type difference_type;
	typedef typename base::iterator_category iterator_category;

	iterator(
		dim_type const &,
		pointer data,
		pointer begin,
		pitch_type const &
	);
private:
	void
	advance(
		difference_type
	);
	
	void
	increment();

	void
	decrement();

	difference_type
	distance_to(
		iterator const &
	) const;

	reference
	dereference() const;

	bool
	equal(
		iterator const &
	) const;

	dim_type dim_;
	pointer
		data_,
		begin_;
	pitch_type pitch_;
};

}
}

#endif
