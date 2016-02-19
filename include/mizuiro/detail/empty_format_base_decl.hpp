//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_EMPTY_FORMAT_BASE_DECL_HPP_INCLUDED
#define MIZUIRO_DETAIL_EMPTY_FORMAT_BASE_DECL_HPP_INCLUDED

#include <mizuiro/detail/empty_format_base_fwd.hpp>


namespace mizuiro
{
namespace detail
{

template<
	typename Store
>
class empty_format_base
{
protected:
	typedef
	Store
	format_store_type;

	constexpr
	explicit
	empty_format_base(
		format_store_type const &
	);

	empty_format_base(
		empty_format_base const &
	) noexcept;

	constexpr
	format_store_type
	format_store_base() const;
};

}
}

#endif
