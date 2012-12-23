//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_ACCESS_HETEROGENOUS_NORMAL_HPP_INCLUDED
#define MIZUIRO_COLOR_ACCESS_HETEROGENOUS_NORMAL_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <mizuiro/access/normal.hpp>
#include <mizuiro/color/format_store_fwd.hpp>
#include <mizuiro/color/is_heterogenous.hpp>
#include <mizuiro/color/access/stride.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace access
{

template<
	typename ColorFormat
>
struct stride<
	::mizuiro::access::normal,
	ColorFormat,
	typename boost::enable_if<
		mizuiro::color::is_heterogenous<
			ColorFormat
		>
	>::type
>
{
	static
	mizuiro::size_type
	execute(
		mizuiro::access::normal const &,
		mizuiro::color::format_store<
			ColorFormat
		> const &
	)
	{
		return
			1u;
	}
};

}
}
}

#endif