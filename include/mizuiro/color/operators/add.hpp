//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_OPERATORS_ADD_HPP_INCLUDED
#define MIZUIRO_COLOR_OPERATORS_ADD_HPP_INCLUDED

#include <mizuiro/color/is_color.hpp>
#include <mizuiro/color/object_impl.hpp>
#include <mizuiro/color/operators/detail/binary_op.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/mpl/and.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/utility/enable_if.hpp>
#include <functional>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace color
{

template<
	typename Color1,
	typename Color2
>
typename boost::enable_if<
	boost::mpl::and_<
		boost::is_same<
			typename Color1::format,
			typename Color2::format
		>,
		color::is_color<
			Color1
		>,
		color::is_color<
			Color2
		>
	>,
	color::object<
		typename Color1::format
	>
>::type
operator+(
	Color1 const &_color1,
	Color2 const &_color2
)
{
	return
		color::operators::detail::binary_op<
			std::plus
		>(
			_color1,
			_color2
		);
}

}
}

#endif
