//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_SPACE_BASE_HPP_INCLUDED
#define MIZUIRO_COLOR_SPACE_BASE_HPP_INCLUDED

#include <mizuiro/color/channel/alpha_fwd.hpp>
#include <mizuiro/color/channel/undefined_fwd.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/contains.hpp>
#include <boost/mpl/fold.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/vector.hpp>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace space
{

template<
	typename Order,
	typename... PossibleChannels
>
struct base
{
	typedef
	Order
	order;

	static_assert(
		boost::mpl::fold<
			Order,
			boost::mpl::true_,
			boost::mpl::and_<
				boost::mpl::_1,
				boost::mpl::contains<
					boost::mpl::vector<
						mizuiro::color::channel::alpha,
						mizuiro::color::channel::undefined,
						PossibleChannels...
					>,
					boost::mpl::_2
				>
			>
		>::type::value,
		"Invalid channel in color space"
	);

	// TODO: Is it ok when channel are missing (e.g. there is only a red channel in rgb)?

	// TODO: Check for duplicates
};

}
}
}

#endif
