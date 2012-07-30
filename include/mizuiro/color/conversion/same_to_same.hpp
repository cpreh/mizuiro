//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERSION_SAME_TO_SAME_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERSION_SAME_TO_SAME_HPP_INCLUDED

#include <mizuiro/color/for_some_channels.hpp>
#include <mizuiro/color/format_argument.hpp>
#include <mizuiro/color/object_impl.hpp>
#include <mizuiro/color/channel/alpha.hpp>
#include <mizuiro/color/channel/undefined.hpp>
#include <mizuiro/color/conversion/detail/copy_or_max_alpha.hpp>
#include <mizuiro/color/conversion/detail/copy_or_min_channel_functor.hpp>
#include <mizuiro/color/conversion/detail/exclude_channel_functor.hpp>
#include <mizuiro/color/conversion/detail/make_logical_and.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/not.hpp>
#include <boost/mpl/placeholders.hpp>
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
mizuiro::color::object<
	Dest
> const
same_to_same(
	Src const &_src,
	typename mizuiro::color::object<
		Dest
	>::format_store_type const &_format
		= mizuiro::color::format_argument<Dest>::get()
)
{
	typedef mizuiro::color::object<
		Dest
	> dest_type;

	dest_type dest(
		_format
	);

	mizuiro::color::for_some_channels<
		boost::mpl::and_<
			boost::mpl::not_<
				boost::is_same<
					mizuiro::color::channel::alpha,
					boost::mpl::_1
				>
			>,
			boost::mpl::not_<
				boost::is_same<
					mizuiro::color::channel::undefined,
					boost::mpl::_1
				>
			>
		>
	>(
		_src,
		mizuiro::color::conversion::detail::copy_or_min_channel_functor<
			Src,
			dest_type
		>(
			_src,
			dest
		),
		mizuiro::color::conversion::detail::make_logical_and(
			mizuiro::color::conversion::detail::exclude_channel_functor<
				typename Src::format,
				channel::alpha
			>(
				_src.format_store()
			),
			mizuiro::color::conversion::detail::exclude_channel_functor<
				typename Src::format,
				channel::undefined
			>(
				_src.format_store()
			)
		)
	);

	mizuiro::color::conversion::detail::copy_or_max_alpha(
		_src,
		dest
	);

	return dest;
}

}
}
}

#endif
