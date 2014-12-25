//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_INIT_DETAIL_ASSIGN_OBJECT_HPP_INCLUDED
#define MIZUIRO_COLOR_INIT_DETAIL_ASSIGN_OBJECT_HPP_INCLUDED

#include <mizuiro/color/object_fwd.hpp>
#include <mizuiro/color/init/detail/values_fwd.hpp>
#include <mizuiro/color/init/detail/visitor.hpp>
#include <mizuiro/detail/tuple_for_each.hpp>


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
inline
void
assign_object(
	mizuiro::color::object<
		Format
	> &_object,
	mizuiro::color::init::detail::values<
		Vector
	> const &_init
)
{
	mizuiro::detail::tuple_for_each(
		mizuiro::color::init::detail::visitor<
			Format
		>(
			_object
		),
		_init.get()
	);
}

}
}
}
}

#endif
