//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERT_STATIC_ALPHA_TO_ANY_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERT_STATIC_ALPHA_TO_ANY_HPP_INCLUDED

#include <mizuiro/color/conversion/alpha_to_any.hpp>
#include <mizuiro/color/is_alpha.hpp>
#include <mizuiro/color/object_impl.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/not.hpp>
#include <boost/utility/enable_if.hpp>

namespace mizuiro
{
namespace color
{
namespace convert_static
{

template<
	typename Dest,
	typename Src
>
typename boost::enable_if<
	boost::mpl::and_<
		boost::mpl::not_<
			color::is_alpha<
				Dest
			>
		>,
		color::is_alpha<
			typename Src::format
		>
	>,
	color::object<
		Dest
	> const
>::type
convert(
	Src const &_src
)
{
	return
		mizuiro::color::conversion::alpha_to_any<
			Dest
		>(
			_src
		);
}

}
}
}

#endif
