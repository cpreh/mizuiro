//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_ACCESS_HOMOGENOUS_RAW_HPP_INCLUDED
#define MIZUIRO_COLOR_ACCESS_HOMOGENOUS_RAW_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <mizuiro/access/raw.hpp>
#include <mizuiro/color/format_store_fwd.hpp>
#include <mizuiro/color/is_homogenous.hpp>
#include <mizuiro/color/access/channel_index.hpp>
#include <mizuiro/color/access/extract_channel.hpp>
#include <mizuiro/color/access/stride.hpp>
#include <mizuiro/color/types/channel_reference.hpp>
#include <mizuiro/color/types/pointer.hpp>
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
	typename Format,
	typename Channel,
	typename Constness
>
struct extract_channel<
	mizuiro::access::raw,
	Format,
	Channel,
	Constness,
	typename boost::enable_if<
		mizuiro::color::is_homogenous<
			Format
		>
	>::type
>
{
	static
	typename mizuiro::color::types::channel_reference<
		mizuiro::access::raw,
		Format,
		Channel,
		Constness
	>::type
	execute(
		mizuiro::access::raw const &,
		mizuiro::color::format_store<
			Format
		> const &_format,
		Channel const &_channel,
		Constness const &,
		typename mizuiro::color::types::pointer<
			mizuiro::access::raw,
			Format,
			Constness
		>::type const _ptr
	)
	{
		return
			typename mizuiro::color::types::channel_reference<
				mizuiro::access::raw,
				Format,
				Channel,
				Constness
			>::type(
				_ptr +
				mizuiro::color::access::channel_index<
					Format,
					Channel
				>::execute(
					_format,
					_channel
				)
				* sizeof(typename Format::channel_type)
			);
	}
};

template<
	typename ColorFormat
>
struct stride<
	mizuiro::access::raw,
	ColorFormat,
	typename boost::enable_if<
		mizuiro::color::is_homogenous<
			ColorFormat
		>
	>::type
>
{
	static
	mizuiro::size_type
	execute(
		mizuiro::access::raw const &,
		mizuiro::color::format_store<
			ColorFormat
		> const &
	)
	{
		return
			ColorFormat::element_count
			* sizeof(typename ColorFormat::channel_type);
	}
};

}
}
}

#endif
