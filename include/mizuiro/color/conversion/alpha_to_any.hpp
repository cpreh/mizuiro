//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERSION_ALPHA_TO_ANY_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERSION_ALPHA_TO_ANY_HPP_INCLUDED

#include <mizuiro/color/for_some_channels.hpp>
#include <mizuiro/color/format_store.hpp>
#include <mizuiro/color/object_impl.hpp>
#include <mizuiro/color/conversion/detail/channel_to_max_functor.hpp>
#include <mizuiro/color/conversion/detail/copy_or_max_alpha.hpp>
#include <mizuiro/color/conversion/detail/exclude_channel_functor.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/mpl/not.hpp>
#include <boost/type_traits/is_same.hpp>
#include <mizuiro/detail/external_end.hpp>


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
alpha_to_any(
	Src const &_src,
	typename color::object<
		Dest
	>::format_store_type const &_format
		= color::format_argument<Dest>::get()
)
{
	typedef
	color::object<
		Dest
	> dest_type;

	dest_type dest(
		_format
	);

	mizuiro::color::for_some_channels<
		boost::mpl::not_<
			boost::is_same<
				mizuiro::color::channel::alpha,
				boost::mpl::placeholders::_1
			>
		>
	>(
		dest,
		detail::channel_to_max_functor<
			dest_type
		>(
			dest
		),
		detail::exclude_channel_functor<
			Dest,
			channel::alpha
		>(
			dest.format_store()
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
}

#endif
