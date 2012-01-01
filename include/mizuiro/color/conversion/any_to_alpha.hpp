//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERSION_ANY_TO_ALPHA_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERSION_ANY_TO_ALPHA_HPP_INCLUDED

#include <mizuiro/color/format_argument.hpp>
#include <mizuiro/color/is_alpha.hpp>
#include <mizuiro/color/object_impl.hpp>
#include <mizuiro/color/conversion/detail/copy_or_max_alpha.hpp>


namespace mizuiro
{
namespace color
{
namespace conversion
{

template<
	typename Dest,
	typename Src
>
color::object<
	Dest
> const
any_to_alpha(
	Src const &_src,
	typename color::object<
		Dest
	>::format_store_type const &_format
		= color::format_argument<Dest>::get()
)
{
	typedef color::object<
		Dest
	> dest_type;

	dest_type dest(
		_format
	);

	detail::copy_or_max_alpha(
		_src,
		dest
	);

	return dest;
}

}
}
}

#endif
