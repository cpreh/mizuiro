//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_OPERATORS_EQUAL_HPP_INCLUDED
#define MIZUIRO_COLOR_OPERATORS_EQUAL_HPP_INCLUDED

#include <mizuiro/color/is_color.hpp>
#include <mizuiro/color/object_impl.hpp>
#include <mizuiro/color/operators/detail/equal.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/begin.hpp>
#include <boost/mpl/end.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/utility/enable_if.hpp>
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
	bool
>::type
operator==(
	Color1 const &_color1,
	Color2 const &_color2
)
{
	typedef typename Color1::format::layout::order channels;

	return
		operators::detail::equal<
			false
		>:: template execute<
			typename boost::mpl::begin<
				channels
			>::type,
			typename boost::mpl::end<
				channels
			>::type
		>(
			_color1,
			_color2
		);
}

}
}

#endif
