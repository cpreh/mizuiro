//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_DETAIL_ITERATOR_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_ITERATOR_DECL_HPP_INCLUDED

#include <mizuiro/difference_type.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/detail/variant_decl.hpp>
#include <mizuiro/image/linear_iterator_decl.hpp>
#include <mizuiro/image/pitch_iterator_decl.hpp>
#include <mizuiro/image/detail/iterator_fwd.hpp>
#include <mizuiro/image/types/pointer.hpp>
#include <mizuiro/image/types/reference.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <type_traits>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace image
{
namespace detail
{

MIZUIRO_DETAIL_IGNORE_EFFCPP

template<
	typename Access,
	typename Format,
	typename Constness
>
class iterator
{
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
	mizuiro::image::pitch_iterator<
		access,
		format,
		constness
	>
	pitch_iterator;

	typedef
	mizuiro::image::linear_iterator<
		access,
		format,
		constness
	>
	linear_iterator;

	static_assert(
		std::is_same<
			typename
			pitch_iterator::format_store_type,
			typename
			linear_iterator::format_store_type
		>::value,
		"pitch_iterator and linear_iterator need the same format store"
	);

	typedef
	typename
	pitch_iterator::format_store_type
	format_store_type;

	typedef
	mizuiro::detail::variant<
		boost::mpl::vector2<
			pitch_iterator,
			linear_iterator
		>
	>
	internal_type;

	typedef
	mizuiro::image::types::reference<
		access,
		format,
		constness
	>
	reference;

	typedef
	mizuiro::image::types::pointer<
		access,
		format,
		constness
	>
	pointer;

	typedef
	mizuiro::difference_type
	difference_type;

	explicit
	iterator(
		internal_type const &
	);

	internal_type const &
	internal() const;

	pointer
	data() const;

/*
	format_store_type const
	format_store() const;*/

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
private:
	internal_type internal_;
};

MIZUIRO_DETAIL_POP_WARNING

}
}
}

#endif
