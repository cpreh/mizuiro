//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERT_STATIC_ANY_TO_ALPHA_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERT_STATIC_ANY_TO_ALPHA_HPP_INCLUDED

#include <mizuiro/color/is_alpha.hpp>
#include <mizuiro/color/object_impl.hpp>
#include <mizuiro/color/conversion/any_to_alpha.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/not.hpp>
#include <boost/utility/enable_if.hpp>
#include <mizuiro/detail/external_end.hpp>


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
		color::is_alpha<
			Dest
		>,
		boost::mpl::not_<
			color::is_alpha<
				typename Src::format
			>
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
		conversion::any_to_alpha<
			Dest
		>(
			_src
		);
}

}
}
}

#endif
