//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_INIT_DETAIL_ASSIGN_OBJECT_HPP_INCLUDED
#define MIZUIRO_COLOR_INIT_DETAIL_ASSIGN_OBJECT_HPP_INCLUDED

#include <mizuiro/color/init/detail/is_single_value.hpp>
#include <mizuiro/color/init/detail/set_channel.hpp>
#include <mizuiro/color/init/detail/visitor.hpp>
#include <boost/fusion/algorithm/iteration/for_each.hpp>
#include <boost/utility/enable_if.hpp>

namespace mizuiro
{
namespace color
{
namespace init
{
namespace detail
{

template<
	typename Object,
	typename Init
>
typename boost::enable_if<
	detail::is_single_value<
		Init
	>,
	void
>::type
assign_object(
	Object &_object,
	Init const &_init
)
{
	set_channel(
		_object,
		_init
	);
}

template<
	typename Object,
	typename Init
>
typename boost::disable_if<
	detail::is_single_value<
		Init
	>,
	void
>::type
assign_object(
	Object &_object,
	Init const &_init
)
{
	boost::fusion::for_each<
		typename Init::vector_type
	>
	(
		_init.get(),
		detail::visitor<
			typename Object::format
		>(
			_object
		)
	);
}

}
}
}
}

#endif
