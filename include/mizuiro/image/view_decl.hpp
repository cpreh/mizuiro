#ifndef MIZUIRO_IMAGE_VIEW_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_VIEW_DECL_HPP_INCLUDED

#include <mizuiro/image/view_fwd.hpp>
#include <mizuiro/image/iterator_fwd.hpp>
#include <mizuiro/image/iterator_pair_fwd.hpp>
#include <mizuiro/image/pitch_iterator_fwd.hpp>
#include <mizuiro/image/linear_iterator_fwd.hpp>
#include <mizuiro/image/bound_fwd.hpp>
#include <mizuiro/detail/nonconst_tag.hpp>
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

	typedef image::iterator_pair<
		pitch_iterator
	> pitch_iterator_pair;

	typedef image::iterator_pair<
		linear_iterator
	> linear_iterator_pair;
	
	typedef sge::variant::object<
		boost::mpl::vector<
			linear_iterator_pair,
			pitch_iterator_pair
		>
	> iterator_pair;

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
		view<
			Format,
			mizuiro::detail::nonconst_tag
		> const &
	);

	dim_type const &
	dim() const;

	iterator const
	begin() const;

	iterator const
	end() const;

	iterator_pair const
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
