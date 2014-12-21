//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMATS_ARE_COMPATIBLE_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMATS_ARE_COMPATIBLE_HPP_INCLUDED

#include <mizuiro/color/types/channel_value_tpl.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/none_t.hpp>
#include <boost/mpl/bind.hpp>
#include <boost/mpl/contains.hpp>
#include <boost/mpl/fold.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/quote.hpp>
#include <boost/type_traits/integral_constant.hpp>
#include <boost/type_traits/is_same.hpp>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace color
{

template<
	typename Format1,
	typename Format2
>
using formats_are_compatible
=
typename
boost::mpl::fold<
	typename Format1::layout::order,
	boost::true_type,
	boost::mpl::and_<
		boost::mpl::_1,
		boost::mpl::bind<
			boost::mpl::quote2<
				boost::is_same
			>,
			boost::mpl::bind<
				boost::mpl::quote2<
					mizuiro::color::types::channel_value_tpl
				>,
				Format1,
				boost::mpl::_2
			>,
			boost::mpl::bind<
				boost::mpl::quote3<
					boost::mpl::if_
				>,
				boost::mpl::bind<
					boost::mpl::quote2<
						boost::mpl::contains
					>,
					typename Format2::layout::order,
					boost::mpl::_2
				>,
				boost::mpl::bind<
					boost::mpl::quote2<
						mizuiro::color::types::channel_value_tpl
					>,
					Format2,
					boost::mpl::_2
				>,
				boost::none_t
			>
		>
	>
>::type;

}
}

#endif
