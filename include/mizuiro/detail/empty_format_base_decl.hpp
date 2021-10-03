//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_EMPTY_FORMAT_BASE_DECL_HPP_INCLUDED
#define MIZUIRO_DETAIL_EMPTY_FORMAT_BASE_DECL_HPP_INCLUDED

#include <mizuiro/detail/empty_format_base_fwd.hpp>
#include <mizuiro/detail/empty_format_store_fwd.hpp>


namespace mizuiro::detail
{

template<
	typename Store
>
class empty_format_base
{
protected:
	using
	format_store_type
	=
	mizuiro::detail::empty_format_store<
		Store
	>;

	constexpr
	explicit
	empty_format_base(
		format_store_type const &
	);

	[[nodiscard]]
	constexpr
	format_store_type
	format_store_base() const;
};

}

#endif
