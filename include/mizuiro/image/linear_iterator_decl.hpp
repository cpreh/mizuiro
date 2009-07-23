#ifndef MIZUIRO_IMAGE_LINEAR_ITERATOR_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_LINEAR_ITERATOR_DECL_HPP_INCLUDED

#include <mizuiro/image/linear_iterator_fwd.hpp>
#include <mizuiro/image/detail/iterator_base.hpp>
#include <mizuiro/detail/apply_const.hpp>

namespace mizuiro
{
namespace image
{

template<
	typename Format,
	typename Constness
>
class linear_iterator
:
	public detail::iterator_base<
		linear_iterator<
			Format,
			Constness
		>,
		Format,
		Constness
	>::type
{
public:
	typedef Format format;

	typedef typename detail::iterator_base<
		linear_iterator<
			format,
			Constness
		>,
		Format,
		Constness
	>::type base;

	typedef typename base::value_type value_type;
	typedef typename base::reference reference;

	typedef typename mizuiro::detail::apply_const<
		typename format::pointer,
		Constness
	>::type pointer;

	typedef typename base::difference_type difference_type;
	typedef typename base::iterator_category iterator_category;

	typedef typename format::pitch_type pitch_type;

	explicit linear_iterator(
		pointer data
	);

	pointer
	data() const;
private:
	friend class boost::iterator_core_access;

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
		linear_iterator const &
	) const;

	reference
	dereference() const;

	bool
	equal(
		linear_iterator const &
	) const;

	pointer data_;
};

}
}

#endif
