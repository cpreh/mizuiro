//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_DIMENSION_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_DIMENSION_DECL_HPP_INCLUDED

#include <mizuiro/array.hpp>
#include <mizuiro/size_type.hpp>
#include <mizuiro/image/dimension_fwd.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <iosfwd>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace image
{

template<
	mizuiro::size_type Dim,
	typename ValueType
>
class dimension
{
public:
	typedef
	ValueType
	value_type;

	typedef
	mizuiro::size_type
	size_type;

	typedef
	value_type &
	reference;

	typedef
	value_type const &
	const_reference;

	typedef
	mizuiro::array<
		value_type,
		Dim
	>
	array_type;

	static
	size_type const static_size
		= Dim;

	typedef
	typename
	array_type::iterator
	iterator;

	typedef
	typename
	array_type::const_iterator
	const_iterator;

	typedef
	typename
	array_type::difference_type
	difference_type;

	dimension();

	template<
		typename... Args
	>
	explicit
	dimension(
		Args && ...
	);

	dimension(
		dimension const &
	) noexcept;

	dimension(
		dimension &&
	);

	dimension(
		dimension const &&
	);

	dimension &
	operator=(
		dimension const &
	);

	dimension &
	operator=(
		dimension &&
	);

	~dimension();

	bool
	empty() const;

	iterator
	begin();

	iterator
	end();

	const_iterator
	begin() const;

	const_iterator
	end() const;

	size_type
	size() const;

	size_type
	content() const;

	reference
	operator[](
		size_type
	);

	const_reference
	operator[](
		size_type
	) const;

	template<
		size_type
	>
	reference
	at_c();

	template<
		size_type
	>
	const_reference
	at_c() const;

	reference
	back();

	const_reference
	back() const;

	void
	swap(
		dimension &
	);

	static
	dimension
	null();
private:
	array_type data_;
};

template<
	mizuiro::size_type Dim,
	typename ValueType
>
void
swap(
	mizuiro::image::dimension<
		Dim,
		ValueType
	> &,
	mizuiro::image::dimension<
		Dim,
		ValueType
	> &
);

template<
	mizuiro::size_type Dim,
	typename ValueType
>
mizuiro::image::dimension<
	Dim,
	ValueType
> const
operator+(
	mizuiro::image::dimension<
		Dim,
		ValueType
	> const &,
	mizuiro::image::dimension<
		Dim,
		ValueType
	> const &
);

template<
	mizuiro::size_type Dim,
	typename ValueType
>
bool
operator==(
	mizuiro::image::dimension<
		Dim,
		ValueType
	> const &,
	mizuiro::image::dimension<
		Dim,
		ValueType
	> const &
);

template<
	mizuiro::size_type Dim,
	typename ValueType
>
bool
operator!=(
	mizuiro::image::dimension<
		Dim,
		ValueType
	> const &,
	mizuiro::image::dimension<
		Dim,
		ValueType
	> const &
);

template<
	mizuiro::size_type Dim,
	typename ValueType,
	typename Ch,
	typename Traits
>
std::basic_ostream<
	Ch,
	Traits
> &
operator<<(
	std::basic_ostream<
		Ch,
		Traits
	> &,
	mizuiro::image::dimension<
		Dim,
		ValueType
	> const &
);

}
}

#endif
