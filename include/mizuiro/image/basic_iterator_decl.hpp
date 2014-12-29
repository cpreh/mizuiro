//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_BASIC_ITERATOR_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_BASIC_ITERATOR_DECL_HPP_INCLUDED

#include <mizuiro/image/basic_iterator_fwd.hpp>
#include <mizuiro/image/types/value_type.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <iterator>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace image
{

template<
	typename Impl
>
class basic_iterator
{
public:
	typedef
	Impl
	impl;

	typedef
	mizuiro::image::types::value_type<
		typename
		Impl::format
	>
	value_type;

	typedef
	typename
	Impl::reference
	reference;

	typedef
	typename
	Impl::pointer
	pointer;

	typedef
	typename
	Impl::difference_type
	difference_type;

	typedef
	std::random_access_iterator_tag
	iterator_category;

	typedef
	typename
	Impl::format_store_type
	format_store_type;

	explicit
	basic_iterator(
		Impl const &
	);

	pointer
	data() const;

	basic_iterator(
		basic_iterator const &
	);

	basic_iterator(
		basic_iterator &&
	);

	basic_iterator &
	operator=(
		basic_iterator const &
	);

	basic_iterator &
	operator=(
		basic_iterator &&
	);

	~basic_iterator();

	reference
	operator*() const;

	basic_iterator &
	operator++();

	bool
	operator==(
		basic_iterator const &
	) const;

	pointer
	operator->() const;

	//basic_iterator();

	basic_iterator &
	operator--();

	basic_iterator &
	operator+=(
		difference_type
	);

	difference_type
	operator-(
		basic_iterator const &
	) const;

	reference
	operator[](
		difference_type
	) const;
private:
	Impl impl_;
};

template<
	typename Impl
>
void
swap(
	mizuiro::image::basic_iterator<
		Impl
	> &,
	mizuiro::image::basic_iterator<
		Impl
	> &
);

template<
	typename Impl
>
bool
operator!=(
	mizuiro::image::basic_iterator<
		Impl
	> const &,
	mizuiro::image::basic_iterator<
		Impl
	> const &
);

template<
	typename Impl
>
mizuiro::image::basic_iterator<
	Impl
>
operator++(
	mizuiro::image::basic_iterator<
		Impl
	> &,
	int
);

template<
	typename Impl
>
mizuiro::image::basic_iterator<
	Impl
>
operator--(
	mizuiro::image::basic_iterator<
		Impl
	> &,
	int
);

template<
	typename Impl
>
mizuiro::image::basic_iterator<
	Impl
>
operator+(
	mizuiro::image::basic_iterator<
		Impl
	>,
	typename
	mizuiro::image::basic_iterator<
		Impl
	>::difference_type
);

template<
	typename Impl
>
mizuiro::image::basic_iterator<
	Impl
>
operator+(
	typename
	mizuiro::image::basic_iterator<
		Impl
	>::difference_type,
	mizuiro::image::basic_iterator<
		Impl
	> const &
);

template<
	typename Impl
>
mizuiro::image::basic_iterator<
	Impl
> &
operator-=(
	mizuiro::image::basic_iterator<
		Impl
	> &,
	typename
	mizuiro::image::basic_iterator<
		Impl
	>::difference_type
);

template<
	typename Impl
>
mizuiro::image::basic_iterator<
	Impl
>
operator-(
	mizuiro::image::basic_iterator<
		Impl
	>,
	typename
	mizuiro::image::basic_iterator<
		Impl
	>::difference_type
);

template<
	typename Impl
>
bool
operator<(
	mizuiro::image::basic_iterator<
		Impl
	> const &,
	mizuiro::image::basic_iterator<
		Impl
	> const &
);

template<
	typename Impl
>
bool
operator>(
	mizuiro::image::basic_iterator<
		Impl
	> const &,
	mizuiro::image::basic_iterator<
		Impl
	> const &
);

template<
	typename Impl
>
bool
operator>=(
	mizuiro::image::basic_iterator<
		Impl
	> const &,
	mizuiro::image::basic_iterator<
		Impl
	> const &
);

template<
	typename Impl
>
bool
operator<=(
	mizuiro::image::basic_iterator<
		Impl
	> const &,
	mizuiro::image::basic_iterator<
		Impl
	> const &
);

}
}

#endif
