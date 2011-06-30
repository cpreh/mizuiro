//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERT_ALPHA_TO_ANY_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERT_ALPHA_TO_ANY_HPP_INCLUDED

#include <mizuiro/color/convert/detail/copy_or_max_alpha.hpp>
#include <mizuiro/color/convert/detail/channel_to_max_functor.hpp>
#include <mizuiro/color/convert/detail/exclude_channel_functor.hpp>
#include <mizuiro/color/for_some_channels.hpp>
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
	typedef 
	color::object<
		Dest
	> dest_type;
	
	dest_type dest;

	mizuiro::color::for_some_channels(
		dest,
		detail::channel_to_max_functor<
			dest_type
		>(
			dest
		),
		detail::exclude_channel_functor<
			Dest,
			channel::alpha
		>()
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
