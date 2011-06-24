//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERT_ANY_TO_ALPHA_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERT_ANY_TO_ALPHA_HPP_INCLUDED

#include <mizuiro/color/convert/detail/copy_or_max_alpha.hpp>
#include <mizuiro/color/is_alpha.hpp>
#include <mizuiro/color/object_impl.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/not.hpp>
#include <boost/utility/enable_if.hpp>

namespace mizuiro
{
namespace color
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
	Src const &_src,
	Dest const &_format = Dest()
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

#endif
