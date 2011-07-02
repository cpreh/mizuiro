//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_NORMAL_FORMAT_BASE_IMPL_HPP_INCLUDED
#define MIZUIRO_DETAIL_NORMAL_FORMAT_BASE_IMPL_HPP_INCLUDED

#include <mizuiro/detail/normal_format_base_fwd.hpp>

template<
	typename Format,
	typename Store
>
mizuiro::detail::normal_format_base<
	Format,
	Store
>::normal_format_base(
	format_store_type const &_format
)
:
	format_(_format)
{
}

template<
	typename Format,
	typename Store
>
typename mizuiro::detail::normal_format_base<
	Format,
	Store
>::format_store_type const
mizuiro::detail::normal_format_base<
	Format,
	Store
>::format_store_base() const
{
	return format_;
}

#endif
