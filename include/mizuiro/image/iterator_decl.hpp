//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ITERATOR_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_ITERATOR_DECL_HPP_INCLUDED

#include <mizuiro/image/iterator_fwd.hpp>
#include <mizuiro/image/pitch_iterator_decl.hpp>
#include <mizuiro/image/linear_iterator_decl.hpp>
#include <mizuiro/image/detail/iterator_base.hpp>
#include <mizuiro/image/types/pointer.hpp>
#include <mizuiro/detail/variant_decl.hpp>
#include <mizuiro/detail/make_variant.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/static_assert.hpp>
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

	typedef Constness constness;

	typedef typename format::color_format color_format;

	typedef typename detail::iterator_base<
		iterator<
			access,
			format,
			constness
		>,
		access,
		format,
		constness
	>::type base;

	typedef image::pitch_iterator<
		access,
		format,
		constness
	> pitch_iterator;

	typedef image::linear_iterator<
		access,
		format,
		constness
	> linear_iterator;

	BOOST_STATIC_ASSERT((
		boost::is_same<
			typename pitch_iterator::format_store_type,
			typename linear_iterator::format_store_type
		>::value
	));

	typedef typename pitch_iterator::format_store_type format_store_type;

	typedef typename mizuiro::detail::make_variant<
		boost::mpl::vector2<
			pitch_iterator,
			linear_iterator
		>
	>::type internal_type;

	typedef typename base::value_type value_type;

	typedef typename base::reference reference;

	typedef typename image::types::pointer<
		access,
		format,
		constness
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

	format_store_type const
	format_store() const;
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
