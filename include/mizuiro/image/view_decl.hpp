#ifndef MIZUIRO_IMAGE_VIEW_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_VIEW_DECL_HPP_INCLUDED

#include <mizuiro/image/view_fwd.hpp>
#include <mizuiro/image/iterator_fwd.hpp>
#include <mizuiro/image/range_fwd.hpp>
#include <mizuiro/image/pitch_iterator_fwd.hpp>
#include <mizuiro/image/linear_iterator_fwd.hpp>
#include <mizuiro/image/bound_fwd.hpp>
#include <sge/variant/object_fwd.hpp>
#include <boost/mpl/vector.hpp>

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

	typedef image::pitch_iterator<
		Format,
		Constness
	> pitch_iterator;

	typedef image::linear_iterator<
		Format,
		Constness
	> linear_iterator;

	typedef image::range<
		pitch_iterator
	> pitch_range;

	typedef image::range<
		linear_iterator
	> linear_range;
	
	typedef sge::variant::object<
		boost::mpl::vector<
			linear_range,
			pitch_range
		>
	> range_type;

	typedef Format format;

	typedef typename format::color_format color_format;

	typedef typename format::dim_type dim_type;

	typedef bound<
		dim_type::static_size,
		typename dim_type::value_type
	> bound_type;

	typedef typename format::pitch_type pitch_type;
	
	typedef typename color_format:: template reference<
		Constness
	>::type reference;

	typedef typename color_format:: template pointer<
		Constness
	>::type pointer;

	view(
		dim_type const &,
		pointer data
	);

	view(
		dim_type const &,
		pointer data,
		pointer sub_data,
		pitch_type const &
	);

	view(
		view const &
	);

	template<
		typename OtherConstness
	>
	explicit view(
		view<
			Format,
			OtherConstness
		> const &
	);

	dim_type const &
	dim() const;

	iterator const
	begin() const;

	iterator const
	end() const;

	range_type const
	range() const;

	reference
	operator[](
		dim_type const &
	) const;

	reference
	at(
		dim_type const &
	) const;

	pointer
	data() const;

	pointer
	sub_data() const;

	pitch_type const &
	pitch() const;
private:
	bool is_linear() const;

	linear_iterator const
	linear_begin() const;

	linear_iterator const
	linear_end() const;

	pitch_iterator const
	pitch_begin() const;

	pitch_iterator const
	pitch_end() const;

	dim_type dim_;
	pointer
		data_,
		sub_data_;
	pitch_type pitch_;
};

}
}

#endif
