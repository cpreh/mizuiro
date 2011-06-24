//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_BASE_DECL_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_BASE_DECL_HPP_INCLUDED

#include <mizuiro/color/format_is_static.hpp>
#include <boost/utility/enable_if.hpp>

namespace mizuiro
{
namespace color
{

template<
	typename Format,
	typename Enable = void
>
class format_base;

template<
	typename Format
>
class format_base<
	Format,
	typename boost::enable_if<
		color::format_is_static<
			Format
		>
	>::type
>
{
protected:
	format_base(
		Format const *
	);

	Format const *
	format_store_base() const;
};

template<
	typename Format
>
class format_base<
	Format,
	typename boost::disable_if<
		color::format_is_static<
			Format
		>
	>::type
>
{
protected:
	format_base(
		Format const *
	);

	Format const *
	format_store_base() const;
private:
	Format const *format_;
};

}
}

#endif
