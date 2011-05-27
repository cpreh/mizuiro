//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERT_SAME_TO_SAME_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERT_SAME_TO_SAME_HPP_INCLUDED

#include <mizuiro/color/convert/detail/copy_and_convert_channel_functor.hpp>
#include <mizuiro/color/convert/detail/copy_or_max_alpha.hpp>
#include <mizuiro/color/channel/alpha.hpp>
#include <mizuiro/color/layout/is_same.hpp>
#include <mizuiro/color/for_some_channels.hpp>
#include <mizuiro/color/object_impl.hpp>
#include <boost/mpl/not.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_same.hpp>

namespace mizuiro
{
namespace color
{

template<
	typename Dest,
	typename Src
>
typename boost::enable_if<
	layout::is_same<
		typename Dest::layout,
		typename Src::format::layout
	>,
	color::object<
		Dest
	> const
>::type
convert(
	Src const &_src
)
{
	typedef color::object<
		Dest
	> dest_type;

	dest_type dest;

	mizuiro::color::for_some_channels<
		Dest,
		boost::mpl::not_<
			boost::is_same<
				boost::mpl::placeholders::_1,
				color::channel::alpha
			>
		>
	>(
		detail::copy_and_convert_channel_functor<
			Src,
			dest_type,
			float
		>(
			_src,
			dest
		)
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
