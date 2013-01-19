//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_VIEW_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_VIEW_DECL_HPP_INCLUDED

#include <mizuiro/detail/make_variant.hpp>
#include <mizuiro/detail/variant_decl.hpp>
#include <mizuiro/image/format_store_fwd.hpp>
#include <mizuiro/image/iterator_fwd.hpp>
#include <mizuiro/image/linear_view_decl.hpp>
#include <mizuiro/image/pitch_view_decl.hpp>
#include <mizuiro/image/view_fwd.hpp>
#include <mizuiro/image/types/pointer.hpp>
#include <mizuiro/image/types/reference.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace image
{

template<
	typename Access,
	typename Format,
	typename Constness
>
class view
{
public:
	typedef Access access;

	typedef Format format;

	typedef Constness constness;

	typedef image::format_store<
		format
	> format_store_type;

	typedef typename image::types::pointer<
		access,
		format,
		constness
	>::type pointer;

	typedef typename image::types::reference<
		access,
		format,
		constness
	>::type reference;

	typedef image::linear_view<
		access,
		format,
		constness
	> linear_view;

	typedef image::pitch_view<
		access,
		format,
		constness
	> pitch_view;

	typedef typename mizuiro::detail::make_variant<
		boost::mpl::vector2<
			linear_view,
			pitch_view
		>
	>::type view_variant;

	typedef mizuiro::image::iterator<
		access,
		format,
		constness
	> iterator;

	typedef typename format::dim dim;

	typedef image::bound<
		dim::static_size,
		typename dim::value_type
	> bound_type;

	typedef typename format::pitch pitch_type;

	explicit view(
		linear_view const &
	);

	explicit view(
		pitch_view const &
	);

	view(
		dim const &,
		pointer data,
		pitch_type const &,
		format_store_type const & =
			mizuiro::image::format_argument<
				format
			>::get()
	);

	view(
		dim const &,
		pointer data,
		format_store_type const & =
			mizuiro::image::format_argument<
				format
			>::get()
	);

	view(
		view const &
	);

	template<
		typename OtherConstness
	>
	explicit view(
		view<
			access,
			format,
			OtherConstness
		> const &
	);

	dim const
	size() const;

	pitch_type const
	pitch() const;

	iterator const
	begin() const;

	iterator const
	end() const;

	reference
	operator[](
		dim const &
	) const;

	pointer
	data() const;

	format_store_type const
	format_store() const;

	view_variant const &
	impl() const;
private:
	view_variant impl_;
};

}
}

#endif
