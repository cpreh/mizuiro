//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_INIT_DETAIL_ASSIGN_OBJECT_HPP_INCLUDED
#define MIZUIRO_COLOR_INIT_DETAIL_ASSIGN_OBJECT_HPP_INCLUDED

#include <mizuiro/color/init/detail/values_fwd.hpp>
#include <mizuiro/color/init/detail/visitor.hpp>
#include <mizuiro/color/object_fwd.hpp>
#include <boost/fusion/algorithm/iteration/for_each.hpp>

namespace mizuiro
{
namespace color
{
namespace init
{
namespace detail
{

template<
	typename Format,
	typename Vector
>
void
assign_object(
	color::object<
		Format
	> &_object,
	detail::values<
		Vector
	> const &_init
)
{
	boost::fusion::for_each<
		Vector
	>
	(
		_init.get(),
		detail::visitor<
			Format
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
