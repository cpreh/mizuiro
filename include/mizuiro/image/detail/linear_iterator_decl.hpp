//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_DETAIL_LINEAR_ITERATOR_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_LINEAR_ITERATOR_DECL_HPP_INCLUDED

#include <mizuiro/difference_type.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/image/detail/linear_iterator_fwd.hpp>
#include <mizuiro/image/format/base_decl.hpp>
#include <mizuiro/image/types/pointer.hpp>
#include <mizuiro/image/types/reference.hpp>


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
class linear_iterator
:
	private
		mizuiro::image::format::base<
			Format
		>
{
public:
	typedef
	mizuiro::image::format::base<
		Format
	>
	format_base;

	typedef
	typename
	format_base::format_store_type
	format_store_type;

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

	linear_iterator(
		pointer,
		format_store_type const &
	);

	pointer
	data() const;

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
private:
	pointer data_;
};

MIZUIRO_DETAIL_POP_WARNING

}
}
}

#endif
