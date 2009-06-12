#ifndef MIZUIRO_IMAGE_ITERATOR_HPP_INCLUDED
#define MIZUIRO_IMAGE_ITERATOR_HPP_INCLUDED

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
		>
	>::type
{
public:
	typedef typename detail::iterator_base<
		iterator<
			Format,
			Constness
		>
	>::type base;

	typedef typename base::value_type value_type;
	typedef typename base::reference reference;
	typedef typename base::pointer pointer;
	typedef typename base::difference_type difference_type;
	typedef typename base::iterator_category iterator_category;

	iterator(
		dim_type const &,
		pointer data
	);
private:
	void advance(
		difference_type
	);
	
	void increment();

	void decrement();

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
	pointer data_;
};

}
}

#endif
