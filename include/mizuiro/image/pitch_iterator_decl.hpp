#ifndef MIZUIRO_IMAGE_PITCH_ITERATOR_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_PITCH_ITERATOR_DECL_HPP_INCLUDED

#include <mizuiro/image/pitch_iterator_fwd.hpp>
#include <mizuiro/image/detail/iterator_base.hpp>
#include <mizuiro/image/detail/pitch_type.hpp>
#include <boost/tr1/array.hpp>

namespace mizuiro
{
namespace image
{

template<
	typename Format,
	typename Constness
>
class pitch_iterator 
:
	public detail::iterator_base<
		pitch_iterator<
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
		pitch_iterator<
			format,
			constness
		>,
		format,
		constness
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

	pitch_iterator(
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
	advance(
		difference_type
	);
	
	void
	increment();

	void
	decrement();

	difference_type
	distance_to(
		pitch_iterator const &
	) const;

	reference
	dereference() const;

	bool
	equal(
		pitch_iterator const &
	) const;

	dim_type dim_;
	pointer
		data_,
		root_data_;
	pitch_type pitch_;

	typedef std::tr1::array<
		typename dim_type::value_type,
		pitch_type::static_size
	> stacked_dim_array;

	stacked_dim_array stacked_dim_;
};

}
}

#endif
