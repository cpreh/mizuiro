//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_BASE_IMPL_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_BASE_IMPL_HPP_INCLUDED

#include <mizuiro/color/format_base_decl.hpp>
#include <mizuiro/color/format_store_impl.hpp>

template<
	typename Format
>
mizuiro::color::format_base<
	Format,
	typename boost::enable_if<
		mizuiro::color::format_is_static<
			Format
		>
	>::type
>::format_base(
	format_store_type const &
)
{
}

template<
	typename Format
>
typename mizuiro::color::format_base<
	Format,
	typename boost::enable_if<
		mizuiro::color::format_is_static<
			Format
		>
	>::type
>::format_store_type const
mizuiro::color::format_base<
	Format,
	typename boost::enable_if<
		mizuiro::color::format_is_static<
			Format
		>
	>::type
>::format_store_base() const
{
	return
		format_store_type(
			0
		);
}

template<
	typename Format
>
mizuiro::color::format_base<
	Format,
	typename boost::disable_if<
		mizuiro::color::format_is_static<
			Format
		>
	>::type
>::format_base(
	format_store_type const &_format
)
:
	format_(_format)
{
}

template<
	typename Format
>
typename mizuiro::color::format_base<
	Format,
	typename boost::disable_if<
		mizuiro::color::format_is_static<
			Format
		>
	>::type
>::format_store_type const
mizuiro::color::format_base<
	Format,
	typename boost::disable_if<
		mizuiro::color::format_is_static<
			Format
		>
	>::type
>::format_store_base() const
{
	return format_;
}

#endif
