//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_ACCESS_HOMOGENOUS_DYNAMIC_HPP_INCLUDED
#define MIZUIRO_ACCESS_HOMOGENOUS_DYNAMIC_HPP_INCLUDED

#include <mizuiro/access/channel_index.hpp>
#include <mizuiro/access/dynamic_index.hpp>
#include <mizuiro/color/is_homogenous_dynamic.hpp>
#include <mizuiro/size_type.hpp>
#include <boost/utility/enable_if.hpp>

namespace mizuiro
{
namespace access
{

template<
	typename Access,
	typename Format,
	typename Channel
>
struct channel_index<
	Access,
	Format,
	Channel,
	typename boost::enable_if<
		mizuiro::color::is_homogenous_dynamic<
			Format
		>
	>::type
>
{
	static
	mizuiro::size_type
	execute(
		Access const &_access,
		Format const *const _format,
		Channel const &_channel
	)
	{
		return
			_format->indices[
				mizuiro::access::dynamic_index<
					Access,
					Format,
					Channel
				>::execute(
					_access,
					*_format,
					_channel
				)
			];
	}
};

}
}

#endif
