//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_DIMENSION_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_DIMENSION_DECL_HPP_INCLUDED

#include <mizuiro/no_init_fwd.hpp>
#include <mizuiro/size_type.hpp>
#include <mizuiro/image/dimension_fwd.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


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
	using
	value_type
	=
	ValueType;

	using
	size_type
	=
	mizuiro::size_type;

	using
	reference
	=
	value_type &;

	using
	const_reference
	=
	value_type const &;

	using
	array_type
	=
	std::array<
		value_type,
		Dim
	>;

	static
	size_type const static_size
		= Dim;

	using
	iterator
	=
	typename
	array_type::iterator;

	using
	const_iterator
	=
	typename
	array_type::const_iterator;

	using
	difference_type
	=
	typename
	array_type::difference_type;

	explicit
	dimension(
		mizuiro::no_init const &
	);

	explicit
	dimension(
		mizuiro::no_init &&
	);

	explicit
	dimension(
		array_type &&
	);

	explicit
	dimension(
		array_type const &
	);

	template<
		typename... Args,
		typename =
			std::enable_if_t<
				std::conjunction_v<
					std::is_constructible<
						value_type,
						fcppt::type_traits::remove_cv_ref_t<
							Args
						>
					>...
				>
			>
	>
	explicit
	dimension(
		Args && ...
	);

	[[nodiscard]]
	iterator
	begin();

	[[nodiscard]]
	iterator
	end();

	[[nodiscard]]
	const_iterator
	begin() const;

	[[nodiscard]]
	const_iterator
	end() const;

	[[nodiscard]]
	reference
	operator[](
		size_type
	);

	[[nodiscard]]
	const_reference
	operator[](
		size_type
	) const;

	template<
		size_type
	>
	[[nodiscard]]
	reference
	at_c();

	template<
		size_type
	>
	[[nodiscard]]
	const_reference
	at_c() const;

	[[nodiscard]]
	reference
	back();

	[[nodiscard]]
	const_reference
	back() const;
private:
	array_type data_;
};

}
}

#endif
