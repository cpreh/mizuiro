//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_OPTIONAL_DECL_HPP_INCLUDED
#define MIZUIRO_DETAIL_OPTIONAL_DECL_HPP_INCLUDED

#include <mizuiro/detail/either_decl.hpp>
#include <mizuiro/detail/nothing.hpp>
#include <mizuiro/detail/optional_fwd.hpp>


namespace mizuiro
{
namespace detail
{

template<
	typename Type
>
class optional
{
public:
	explicit
	optional(
		mizuiro::detail::nothing
	);

	explicit
	optional(
		Type const &
	);

	optional(
		optional const &
	) noexcept;

	optional(
		optional &&
	) noexcept;

	optional &
	operator=(
		optional const &
	);

	optional &
	operator=(
		optional &&
	) noexcept;

	~optional();

	bool
	has_value() const;

	Type const &
	get() const;
private:
	typedef
	mizuiro::detail::either<
		Type,
		mizuiro::detail::nothing
	>
	impl;

	impl impl_;
};

}
}

#endif
