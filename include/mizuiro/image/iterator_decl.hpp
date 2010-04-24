#ifndef MIZUIRO_IMAGE_ITERATOR_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_ITERATOR_DECL_HPP_INCLUDED

#include <mizuiro/image/iterator_fwd.hpp>
#include <mizuiro/image/pitch_iterator_decl.hpp>
#include <mizuiro/image/linear_iterator_decl.hpp>
#include <mizuiro/image/detail/iterator_base.hpp>
#include <mizuiro/image/types/pointer.hpp>
#include <fcppt/variant/object_decl.hpp>
#include <boost/mpl/vector/vector10.hpp>

namespace mizuiro
{
namespace image
{

template<
	typename Access,
	typename Format,
	typename Constness
>
class iterator
:
	public detail::iterator_base<
		iterator<
			Access,
			Format,
			Constness
		>,
		Access,
		Format,
		Constness
	>::type
{
public:
	typedef Access access;

	typedef Format format;

	typedef typename format::color_format color_format;

	typedef typename detail::iterator_base<
		iterator<
			access,
			format,
			Constness
		>,
		access,
		format,
		Constness
	>::type base;

	typedef fcppt::variant::object<
		boost::mpl::vector2<
			pitch_iterator<
				access,
				format,
				Constness
			>,
			linear_iterator<
				access,
				format,
				Constness
			>
		>
	> internal_type;

	typedef typename base::value_type value_type;

	typedef typename base::reference reference;

	typedef typename image::types::pointer<
		access,
		format,
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
