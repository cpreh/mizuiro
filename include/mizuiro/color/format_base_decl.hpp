//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_BASE_DECL_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_BASE_DECL_HPP_INCLUDED

#include <mizuiro/color/format_is_static.hpp>
#include <mizuiro/color/format_store_decl.hpp>
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
	typedef color::format_store<
		Format
	> format_store_type;

	explicit format_base(
		format_store_type const &
	);

	format_store_type const
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
	typedef color::format_store<
		Format
	> format_store_type;

	explicit format_base(
		format_store_type const &
	);

	format_store_type const
	format_store_base() const;
private:
	format_store_type format_;
};

}
}

#endif
