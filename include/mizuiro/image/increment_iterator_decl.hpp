#ifndef MIZUIRO_IMAGE_INCREMENT_ITERATOR_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_INCREMENT_ITERATOR_DECL_HPP_INCLUDED

#include <mizuiro/image/increment_iterator_fwd.hpp>
#include <mizuiro/image/detail/iterator_base.hpp>
#include <mizuiro/image/detail/pitch_type.hpp>
#include <boost/iterator/iterator_facade.hpp>

namespace mizuiro
{
namespace image
{

template<
	typename Format,
	typename Constness
>
class increment_iterator 
:
	public detail::iterator_base<
		increment_iterator<
			Format,
			Constness
		>,
		Format,
		Constness,
		boost::forward_traversal_tag
	>::type
{
public:
	typedef Format format;
	typedef Constness constness; 

	typedef typename detail::iterator_base<
		increment_iterator<
			format,
			constness
		>,
		format,
		constness,
		boost::forward_traversal_tag
	>::type base;

	typedef typename format::dim_type dim_type;

	typedef typename detail::pitch_type<
		dim_type
	>::type pitch_type;

	typedef typename base::value_type value_type;
	typedef typename base::reference reference;

	typedef typename format::color_format::template pointer<
		Constness
	>::type pointer;

	typedef typename base::difference_type difference_type;
	typedef typename base::iterator_category iterator_category;

	increment_iterator(
		dim_type const &,
		pointer data,
		pitch_type const &
	);

	dim_type const &
	dim() const;

	pointer
	data() const;

	pointer
	root_data() const;

	pitch_type const &
	pitch() const;
private:
	friend class boost::iterator_core_access;

	void
	increment();

	reference
	dereference() const;

	bool
	equal(
		increment_iterator const &
	) const;

	dim_type dim_;
	pointer
		data_,
		root_data_;
	pitch_type pitch_;
};

}
}

#endif
