//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_DETAIL_INDEXED_ITERATOR_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_INDEXED_ITERATOR_DECL_HPP_INCLUDED

#include <mizuiro/image/indexed_ref_fwd.hpp>
#include <mizuiro/image/detail/indexed_iterator_fwd.hpp>


namespace mizuiro
{
namespace image
{
namespace detail
{

template<
	typename Dimension,
	typename Underlying
>
class indexed_iterator
{
public:
	indexed_iterator(
		Dimension const &_total_size,
		Dimension const &_current,
		Underlying const &
	);

	typedef
	mizuiro::image::indexed_ref<
		Dimension::static_size,
		typename
		Underlying::reference
	>
	reference;

	typedef
	typename
	Underlying::pointer
	pointer;

	typedef
	typename
	Underlying::difference_type
	difference_type;

	typedef
	typename
	Underlying::format
	format;

	typedef
	typename
	Underlying::format_store_type
	format_store_type;

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
		indexed_iterator const &
	) const;

	reference
	dereference() const;

	bool
	equal(
		indexed_iterator const &
	) const;
private:
	Dimension size_;

	Dimension current_;

	Underlying underlying_;
};

}
}
}

#endif
