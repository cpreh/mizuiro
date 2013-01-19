//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_ACCESS_HETEROGENOUS_HPP_INCLUDED
#define MIZUIRO_COLOR_ACCESS_HETEROGENOUS_HPP_INCLUDED

#include <mizuiro/color/format_store_fwd.hpp>
#include <mizuiro/color/is_heterogenous.hpp>
#include <mizuiro/color/access/extract_channel.hpp>
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
	typename Access,
	typename Format,
	typename Channel,
	typename Constness
>
struct extract_channel<
	Access,
	Format,
	Channel,
	Constness,
	typename boost::enable_if<
		mizuiro::color::is_heterogenous<
			Format
		>
	>::type
>
{
	static
	typename mizuiro::color::types::channel_reference<
		Access,
		Format,
		Channel,
		Constness
	>::type
	execute(
		Access,
		mizuiro::color::format_store<
			Format
		> const &,
		Channel const &,
		Constness const &,
		typename mizuiro::color::types::pointer<
			Access,
			Format,
			Constness
		>::type const _ptr
	)
	{
		return
			typename mizuiro::color::types::channel_reference<
				Access,
				Format,
				Channel,
				Constness
			>::type(
				_ptr
			);
	}
};


}
}
}

#endif
