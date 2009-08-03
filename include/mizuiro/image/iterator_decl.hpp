#ifndef MIZUIRO_IMAGE_ITERATOR_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_ITERATOR_DECL_HPP_INCLUDED

#include <mizuiro/image/iterator_fwd.hpp>
#include <mizuiro/image/pitch_iterator_decl.hpp>
#include <mizuiro/image/linear_iterator_decl.hpp>
#include <mizuiro/image/detail/iterator_base.hpp>
#include <sge/variant/object_decl.hpp>
#include <boost/mpl/vector.hpp>

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

	typedef typename detail::iterator_base<
		iterator<
			format,
			Constness
		>,
		Format,
		Constness
	>::type base;

	typedef sge::variant::object<
		boost::mpl::vector<
			pitch_iterator<
				Format,
				Constness
			>,
			linear_iterator<
				Format,
				Constness
			>
		>
	> internal_type;

	typedef typename base::value_type value_type;
	typedef typename base::reference reference;

	typedef typename format::color_format:: template pointer<
		Constness
	>::type pointer;

	typedef typename base::difference_type difference_type;
	typedef typename base::iterator_category iterator_category;

	explicit iterator(
		internal_type const &
	);

	internal_type const &
	internal() const;

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
		iterator const &
	) const;

	reference
	dereference() const;

	bool
	equal(
		iterator const &
	) const;

	internal_type internal_;
};

}
}

#endif
