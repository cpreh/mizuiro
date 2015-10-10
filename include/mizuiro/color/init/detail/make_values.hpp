//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_INIT_DETAIL_MAKE_VALUES_HPP_INCLUDED
#define MIZUIRO_COLOR_INIT_DETAIL_MAKE_VALUES_HPP_INCLUDED

#include <mizuiro/color/init/detail/values.hpp>


namespace mizuiro
{
namespace color
{
namespace init
{
namespace detail
{

template<
	typename Vector
>
inline
mizuiro::color::init::detail::values<
	Vector
>
make_values(
	Vector const &_vector
)
{
	return
		mizuiro::color::init::detail::values<
			Vector
		>(
			_vector
		);
}

}
}
}
}

#endif
