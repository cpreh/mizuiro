//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_LINEAR_ITERATOR_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_LINEAR_ITERATOR_DECL_HPP_INCLUDED

#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/image/linear_iterator_fwd.hpp>
#include <mizuiro/image/format/argument.hpp>
#include <mizuiro/image/format/base_decl.hpp>
#include <mizuiro/image/detail/iterator_base.hpp>
#include <mizuiro/image/types/pointer.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/iterator/iterator_facade.hpp>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace image
{

MIZUIRO_DETAIL_IGNORE_EFFCPP

template<
	typename Access,
	typename Format,
	typename Constness
>
class linear_iterator
:
	public
		mizuiro::image::detail::iterator_base<
			mizuiro::image::linear_iterator<
				Access,
				Format,
				Constness
			>,
			Access,
			Format,
			Constness
		>,
	private
		mizuiro::image::format::base<
			Format
		>::type
{
	typedef
	typename
	mizuiro::image::format::base<
		Format
	>::type
	format_base;
public:
	typedef
	Access
	access;

	typedef
	Format
	format;

	typedef
	Constness
	constness;

	typedef
	typename
	format_base::format_store_type
	format_store_type;

	typedef
	mizuiro::image::detail::iterator_base<
		mizuiro::image::linear_iterator<
			access,
			format,
			constness
		>,
		access,
		format,
		constness
	>
	base;

	typedef
	typename
	base::value_type value_type;

	typedef
	typename
	base::reference reference;

	typedef
	mizuiro::image::types::pointer<
		access,
		format,
		Constness
	>
	pointer;

	typedef
	typename
	base::difference_type
	difference_type;

	typedef
	typename
	base::iterator_category
	iterator_category;

	typedef
	typename
	format::pitch
	pitch_type;

	explicit
	linear_iterator(
		pointer data,
		format_store_type const & =
			mizuiro::image::format::argument<
				format
			>::get()
	);

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

MIZUIRO_DETAIL_POP_WARNING

}
}

#endif
