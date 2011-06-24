//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_BASE_IMPL_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_BASE_IMPL_HPP_INCLUDED

#include <mizuiro/color/format_base_decl.hpp>

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
	Format const *
)
{
}

template<
	typename Format
>
Format const *
mizuiro::color::format_base<
	Format,
	typename boost::enable_if<
		mizuiro::color::format_is_static<
			Format
		>
	>::type
>::format_store_base() const
{
	return 0;
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
	Format const *const _format
)
:
	format_(_format)
{
}

template<
	typename Format
>
Format const *
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
